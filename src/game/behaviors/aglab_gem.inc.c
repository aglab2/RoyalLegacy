extern struct ObjectHitbox sCollectStarHitbox;
static int gemGetModelId(void)
{
    return 0xf6 + gCurrCourseNum - 1;
}

void bhv_gem_init()
{
    o->header.gfx.sharedChild = gLoadedGraphNodes[gemGetModelId()];
    obj_set_hitbox(o, &sCollectStarHitbox);
    o->oFaceAnglePitch = 0x4000;
    o->oInteractionSubtype |= (INT_SUBTYPE_NO_EXIT | INT_SUBTYPE_GEM);
    obj_scale(o, 2.4f);

    if (save_file_is_gem_collected())
    {
        o->activeFlags = 0;
    }
}

void bhv_gem_loop()
{
    o->oFaceAngleYaw += 0x800;

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        obj_mark_for_deletion(o);
        o->oInteractStatus = INT_STATUS_NONE;
    }
}
