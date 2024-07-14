extern const Collision beta_door_r_collision[];
extern const Collision beta_door_l_collision[];

void bhv_epic_door()
{
    if (0 == o->oBehParams2ndByte)
    {
        obj_set_collision_data(o, beta_door_l_collision);
    }
    else
    {
        obj_set_collision_data(o, beta_door_r_collision);
    }

    s32 flags = save_file_get_flags();
    // if ((flags & SAVE_FILE_RL_GEMS) == SAVE_FILE_RL_GEMS)
    if (1)
    {
        static const Vec3f kPivot = { 1030, -711, -4167 };
        Vec3f dist;
        vec3_diff(dist, kPivot, gMarioStates->pos);
        f32 mag = vec3_mag(dist);

        if (1 == o->oAction)
        {
            if (1 == o->oBehParams2ndByte)
            {
                if (o->oMoveAngleYaw < 0x3000)
                {
                    o->oMoveAngleYaw += 0x100;
                    cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
                }
            }
            else
            {
                if (o->oMoveAngleYaw > -0x3000)
                {
                    o->oMoveAngleYaw -= 0x100;
                    cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
                }
            }

            if (mag > 2000.f)
            {
                o->oAction = 0;
            }
        }
        else
        {
            if (o->oMoveAngleYaw < 0)
            {
                o->oMoveAngleYaw += 0x100;
                cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
            }
            if (o->oMoveAngleYaw > 0)
            {
                o->oMoveAngleYaw -= 0x100;
                cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
            }

            if (mag < 1000.f)
            {
                o->oAction = 1;
            }
        }
    }
}
