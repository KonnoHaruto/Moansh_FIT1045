using static SplashKitSDK.SplashKit;
using static System.Convert;

string line;

do
{
    WriteLine("1: Say hello");
    WriteLine("2: ...");
    WriteLine("3: Quit");

    line = ReadLine();

    switch (line)
    {
        case "1":
            WriteLine("Hello!");
            break;
        case "2":
            WriteLine("...!");
            break;
        case "3":
            break;
        default:
            WriteLine("Please enter a menu option");
            break;
    }
} while (line != "3");