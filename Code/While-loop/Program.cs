using System.Diagnostics;
using static SplashKitSDK.SplashKit;
using static System.Convert;

string line;
int value;
int i;

Write("Enter a number: ");
line = ReadLine();
value = ToInt32(line);

i = 0;

while (i < value)
{
    WriteLine("Hello World! " + i);

    i++;
}

OpenWindow("Test Window", 400, 300);

while (!QuitRequested())
{
    FillCircle(RandomColor(), Rnd(400), Rnd(300), Rnd(50));
    RefreshScreen();

    ProcessEvents(); // 
}