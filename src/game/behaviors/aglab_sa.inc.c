#define oSACoin0 oObjF4
#define oSACoin1 oObjF8
#define oSACoin2 oObjFC
#define oSACoin3 oObj100

void bhv_sa_ladder_init()
{
    o->oSACoin0 = spawn_object(o, MODEL_YELLOW_COIN, bhvOneCoin);
    o->oSACoin0->oPosX = 4898.0f;
    o->oSACoin0->oPosY = 1124.0f;
    o->oSACoin0->oPosZ = 3380.0f;
    
    o->oSACoin1 = spawn_object(o, MODEL_YELLOW_COIN, bhvOneCoin);
    o->oSACoin1->oPosX = 4544.0f;
    o->oSACoin1->oPosY = 1124.0f;
    o->oSACoin1->oPosZ = 3380.0f;
    
    o->oSACoin2 = spawn_object(o, MODEL_YELLOW_COIN, bhvOneCoin);
    o->oSACoin2->oPosX = 4898.0f;
    o->oSACoin2->oPosY = 1124.0f;
    o->oSACoin2->oPosZ = 3016.0f;
    
    o->oSACoin3 = spawn_object(o, MODEL_YELLOW_COIN, bhvOneCoin);
    o->oSACoin3->oPosX = 4544.0f;
    o->oSACoin3->oPosY = 1124.0f;
    o->oSACoin3->oPosZ = 3016.0f;

    cur_obj_hide();
    o->oDrawingDistance = 30000.0f;
}

void bhv_sa_ladder_loop()
{
    struct Object** objs = &o->oSACoin0;
    
    {
        struct Object* coin = objs[o->oAction];
        if (coin && !coin->activeFlags)
        {
            o->oAction++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        struct Object* coin = objs[i];
        if (coin && !coin->activeFlags)
        {
            coin = NULL;
        }
    }

    if (4 == o->oAction)
    {
        cur_obj_unhide();
        load_object_collision_model();
    }
}
