#pragma once

#include "MainWindow.g.h"
#include "ServerManager.h"
#include <thread>
#include <mutex>


#define BUFFSIZE 4096

namespace winrt::VChat_WinUI3::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
            serv_h = (server_manage::ServerManager*)new server_manage::ServerManager(9999);
            //Closed(&MainWindow::Exit_Func);
        }

    private: bool isStarted; // Bool to track if we have started the server or not
    private: std::thread t_handle; // Thread Handle
    //private: std::mutex t_mutex; // Since we are marshaling the UI Thread this is not really needed.
    private: server_manage::ServerManager* serv_h;
    public:
        int32_t MyProperty();
        void MyProperty(int32_t value);
        void Exit_Func(void);

        // Function To Manage Blocking Writes to the Textbox
        void Write_Text_Box_Block(winrt::hstring);

        void Start_Button_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Stop_Button_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    public: 
        void Server_Listener_N(winrt::Microsoft::UI::Dispatching::DispatcherQueue dispatcherQueue);
        void Server_Listener() {}
    };
}

namespace winrt::VChat_WinUI3::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
