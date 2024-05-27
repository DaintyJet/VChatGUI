#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::VChat_WinUI3::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    /* Exit Function to kill the server 
    * 
    * @param: None
    * 
    * @return: None
    */
    void MainWindow::Exit_Func() {
        if (this->isStarted)
            return;

        this->serv_h->killServer();
        delete this->serv_h;

        return;
    }

    /* 
    * Background function for listening and writing server output 
    * to the texbox window
    * 
    * @param dispatcherQueue: Dispatcher Queue to enqueue the function call onto.
    * 
    * @return: None
    */
    void MainWindow::Server_Listener_N(winrt::Microsoft::UI::Dispatching::DispatcherQueue dispatcherQueue) {
        char buff[BUFFSIZE] = { 0 };

        // Catch any exceptions thrown by killing the processes we are 
        // trying to read from
        while (1) {
            if (this->serv_h->serverRead(buff, BUFFSIZE) == -1) {
                std::cout << GetLastError() << "\n";
                break;
            }
            // Convert char buffer to hstring.
            winrt::hstring converted = winrt::to_hstring(buff);
            // Need to use dispatcher Queues, Need to learn what they are. 
            try {
                dispatcherQueue.TryEnqueue([this, converted]()
                    {
                        this->Write_Text_Box_Block(converted);
                    });
             }
            catch (std::exception e) {
                return;
            }
        }
        return; // We should never get here
    }

    /*
    * Write message out to the text window of the GUI and autoscroll
    * 
    * @param textBlock: textstring to write to output window.
    * 
    * @return: None
    */
    void MainWindow::Write_Text_Box_Block(winrt::hstring textBlock) {
        auto txt = VChatOutput();
        VChatOutput().Text(VChatOutput().Text() + textBlock);
        //VChatOutput().AppendText(L"Test");
       // ScrollViewerVChat().ChangeView(NULL, ScrollViewerVChat().ExtentHeight(), NULL);
        ScrollViewerVChat().ChangeView(nullptr, ScrollViewerVChat().ScrollableHeight(), nullptr);

        return;
    }

    /* Start Button Handler */
    void MainWindow::Start_Button_Click(IInspectable const&, RoutedEventArgs const&)
    {
        this->Write_Text_Box_Block(L"Started Server");
        if (this->isStarted == 1)
            return;
        

        if (this->serv_h->initPipes() == -1) {
            return;
        }
        if (this->serv_h->CreateServerProcess("C:\\Local-Git\\VChatGUI\\SRC\\Test-Child\\x64\\Debug\\Test-Child.exe") == -1) {
            return;
        }
       
        this->t_handle = std::thread(&MainWindow::Server_Listener_N, this, winrt::Microsoft::UI::Dispatching::DispatcherQueue::GetForCurrentThread());
        //this->t_handle.detach();
        //this->t_handle.~thread();

        //Start_Button().Content(box_value(L"Clicked"));
        this->serv_h->set_isStarted(1);
        this->isStarted = 1;
        return;
    }

    /* Start Button Handler */
    void MainWindow::Stop_Button_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args) {
        if (this->isStarted == 0)
            return;

        this->serv_h->killServer();
        
        this->serv_h->set_isStarted(0);
        this->isStarted = 0;
        return;
    }

}
