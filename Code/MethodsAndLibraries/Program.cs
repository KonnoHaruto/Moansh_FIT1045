using static SplashKitSDK.SplashKit;

// Give us access to convert methods from C#
using static System.Convert;

string userInput;
int width, height, delaySeconds;

// Output a message
WriteLine("Window Test");

Write("How wide do you want the window? Enter width: ");
userInput = ReadLine();

// Call ToInt32 from Convert
width = ToInt32(userInput);

Write("How high do you want the window? Enter height: ");
userInput = ReadLine();

// Call ToInt32 from Convert
height = ToInt32(userInput);

Write("How many seconds do you want it to show for? Enter seconds: ");
userInput = ReadLine();

delaySeconds = ToInt32(userInput);

// Call open window from SplashKit
OpenWindow("Test Window", width, height);

ClearScreen(RandomColor());
RefreshScreen();

Delay(delaySeconds * 1000);

CloseAllWindows();
