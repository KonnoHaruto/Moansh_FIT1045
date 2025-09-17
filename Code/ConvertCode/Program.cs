  using SplashKitSDK;
  using static SplashKitSDK.SplashKit;

  const int PLAYER_RADIUS = 50;
  const int PLAYER_SPEED = 3;

  int playerX = 640;

  OpenWindow("Circle Moving", 1280, 720);

  while( ! QuitRequested() )
  {
      ClearScreen(ColorWhite());
      FillCircle(ColorTurquoise(), playerX, 360, PLAYER_RADIUS);
      RefreshScreen(60);

      ProcessEvents();

      if ( KeyDown(KeyCode.RightKey) )
      {
          playerX += PLAYER_SPEED;
      }

      if ( KeyDown(KeyCode.LeftKey) )
      {
          playerX -= PLAYER_SPEED;
      }
  }