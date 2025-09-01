using static SplashKitSDK.SplashKit;

// Open a window, before drawing to it
OpenWindow("A House", 800, 600);

// Clear the screen to white - dont show it yet
ClearScreen(ColorWhite());

// Draw a hill like ellipse - only half of the ellipse is shown
FillEllipse(ColorBrightGreen(), 0, 400, 800, 400);

// Draw a house shape - rectangular walls, triangular roof
FillRectangle(ColorGray(), 300, 300, 200, 200);
FillTriangle(ColorRed(), 250, 300, 400, 150, 550, 300);

// Now show the picture we have drawn to the user
RefreshScreen();

// Wait for 5 seconds
Delay(5000);
