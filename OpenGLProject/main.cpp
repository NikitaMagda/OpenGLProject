#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <gl\GLU.h>
#include "Include\GL\glext.h"
#include "Include\GL\wglext.h"

#pragma comment(lib, "opengl32.lib")

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//auto polygonMode = GL_FILL;
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

//const GLchar* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"}\0";

//const GLchar* fragmentShaderSource = "#version 330 core\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";

int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    hInst = hInstance; // Store instance handle in our global variable  

                       // The parameters to CreateWindow explained:  
                       // szWindowClass: the name of the application  
                       // szTitle: the text that appears in the title bar  
                       // WS_OVERLAPPEDWINDOW: the type of window to create  
                       // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
                       // 500, 100: initial size (width, length)  
                       // NULL: the parent of this window  
                       // NULL: this application dows not have a menu bar  
                       // hInstance: the first parameter from WinMain  
                       // NULL: not used in this application  
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        1280, 720,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:  
    // hWnd: the value returned from CreateWindow  
    // nCmdShow: the fourth parameter from WinMain  
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:  
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;



    int major = 0, minor = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    printf("OpenGL context created.\nVersion %d.%d\nVendor %s\nRenderer %s\n",
        major, minor,
        glGetString(GL_VENDOR),
        glGetString(GL_RENDERER));
    //glfwInit();
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    //GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    //const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
    //GLFWwindow* window = glfwCreateWindow(videoMode->width, videoMode->height, "OpenGL Project", primaryMonitor, nullptr);
    //if (window == nullptr)
    //{
    //    std::cout << "Failed to create window" << std::endl;
    //    glfwTerminate();
    //    return -1;
    //}
    //glfwMakeContextCurrent(window);
    //glfwSetKeyCallback(window, key_callback);

    //glewExperimental = GL_TRUE;
    //if (glewInit() != GLEW_OK)
    //{
    //    std::cout << "Failed to initialize GLEW" << std::endl;
    //    return -1;
    //}

    //int width, height;
    //glfwGetFramebufferSize(window, &width, &height);
    //glViewport(0, 0, width, height);

    //glfwSwapInterval(0);

    //double lastTime = glfwGetTime();
    //int nbFrames = 0;

    //GLint success;
    //GLchar infoLog[512];

    //GLuint vertexShader;
    //vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    //glCompileShader(vertexShader);

    //glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    //if (!success)
    //{
    //    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    //}

    //GLuint fragmentShader;
    //fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    //glCompileShader(fragmentShader);

    //glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    //if (!success)
    //{
    //    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    //    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    //}

    //GLuint shaderProgram;
    //shaderProgram = glCreateProgram();

    //glAttachShader(shaderProgram, vertexShader);
    //glAttachShader(shaderProgram, fragmentShader);
    //glLinkProgram(shaderProgram);

    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    //if (!success) {
    //    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    //    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    //}
    //glDeleteShader(vertexShader);
    //glDeleteShader(fragmentShader);

    GLfloat triangle[] = {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };
    //GLuint indices[] = {
    //    0, 1, 3,
    //    1, 2, 3
    //};

    //GLuint VBO, VAO, EBO;
    //glGenBuffers(1, &VBO);
    //glGenVertexArrays(1, &VAO);
    //glGenBuffers(1, &EBO);

    //glBindVertexArray(VAO);

    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    //glEnableVertexAttribArray(0);

    //glBindVertexArray(0);

    //while (!glfwWindowShouldClose(window))
    //{
    //    // fps counter
    //    double currentTime = glfwGetTime();
    //    nbFrames++;
    //    if (currentTime - lastTime >= 1.0) {
    //        printf("%f ms/frame, %i fps\n", 1000.0 / double(nbFrames), nbFrames);
    //        nbFrames = 0;
    //        lastTime += 1.0;
    //    }

    //    glfwPollEvents();

    //    glClearColor(0.2f, 0.4f, 0.1f, 1.0f);
    //    glClear(GL_COLOR_BUFFER_BIT);

    //    glUseProgram(shaderProgram);
    //    glBindVertexArray(VAO);
    //    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    //    glBindVertexArray(0);

    //    glfwSwapBuffers(window);
    //}

    //glfwTerminate();
    Sleep(999999);
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, World!");

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}

//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//    {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//    else if (key == GLFW_KEY_Q && action == GLFW_PRESS)
//    {
//        polygonMode = polygonMode == GL_LINE ? GL_FILL : GL_LINE;
//        glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
//    }
//}