extern const Collision beta_door_r_collision[];
extern const Collision beta_door_l_collision[];

void bhv_epic_door()
{
    if (0 == o->oBehParams2ndByte)
    {
        obj_set_collision_data(o, beta_door_r_collision);
    }
    else
    {
        obj_set_collision_data(o, beta_door_l_collision);
    }
}
