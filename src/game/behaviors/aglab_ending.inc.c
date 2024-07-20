void bhv_ending_player_init()
{
    set_cam_angle(2); // lakitu cam
    gHudDisplay.flags = HUD_DISPLAY_NONE;
    o->oHealth = 0x880;
}

void bhv_ending_player_loop()
{
    struct MarioStates* m = gMarioStates;
    set_mario_action(m, 0, 0);
    gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[0];
    gPlayer1Controller->buttonDown = 0;
    gPlayer1Controller->buttonPressed = 0;
    gPlayer1Controller->stickX = 0;
    gPlayer1Controller->stickY = 0;
    gPlayer1Controller->rawStickX = 0;
    gPlayer1Controller->rawStickY = 0;
    auto camera = gCurrentArea->camera;
    set_camera_mode_8_directions(camera);
    reset_camera(camera);
}
