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

    void MainWindow::Exit_Func() {
        if (this->isStarted)
            return;

        this->serv_h->killServer();
        delete this->serv_h;

        return;
    }

    void MainWindow::Server_Listener() {
        char buff[BUFFSIZE];

        // Catch any exceptions thrown by killing the processes we are 
        // trying to read from
        while (1) {
            if (this->serv_h->serverRead(buff, BUFFSIZE) == -1) {
                std::cout << GetLastError() << "\n";
                break;
            }
            std::cout << buff << "\n";
            std::string converted = std::string(buff);
            // Need to use dispatcher Queues, Need to learn what they are. 
            this->Write_Text_Box_Block(converted);
        }

    }

    void MainWindow::Write_Text_Box_Block(std::string textBlock) {
       // t_mutex->WaitOne();
        //VChatOutput.Text += "Test";
        auto txt = VChatOutput();
        VChatOutput().Text(VChatOutput().Text() + L"New text appended\n");
        //t_mutex->ReleaseMutex();
        return;
    }
    void MainWindow::Start_Button_Click(IInspectable const&, RoutedEventArgs const&)
    {
        this->Write_Text_Box_Block("Started Server");
        if (this->isStarted == 1)
            return;

        if (this->serv_h->initPipes() == -1) {
            return;
        }
        if (this->serv_h->CreateServerProcess("C:\\Local-Git\\VChatGUI\\SRC\\Test-Child\\x64\\Debug\\Test-Child.exe") == -1) {
            return;
        }
       
        this->t_handle = std::thread(&MainWindow::Server_Listener, this);
        this->t_handle.detach();
        this->t_handle.~thread();

        //Start_Button().Content(box_value(L"Clicked"));
        this->serv_h->set_isStarted(1);
        this->isStarted = 1;
        return;
    }

    void MainWindow::Stop_Button_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args) {
        if (this->isStarted == 0)
            return;

        this->serv_h->killServer();
        
        this->serv_h->set_isStarted(0);
        this->isStarted = 0;
        return;
    }

}
