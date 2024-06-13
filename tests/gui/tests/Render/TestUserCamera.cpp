/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test camera
*/

#include "Render/UserCamera.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(UserCamera, get_position, .timeout = 5)
{
    Gui::UserCamera cam;

    cr_assert_eq(cam.getPosition().x, 5.0f);
    cr_assert_eq(cam.getPosition().y, 5.0f);
    cr_assert_eq(cam.getPosition().z, 5.0f);
}

Test(UserCamera, set_position, .timeout = 5)
{
    Gui::UserCamera cam;

    cam.setPosition((Vector3){1.0f, 1.0f, 1.0f});

    cr_assert_eq(cam.getPosition().x, 1.0f);
    cr_assert_eq(cam.getPosition().y, 1.0f);
    cr_assert_eq(cam.getPosition().z, 1.0f);
}

Test(UserCamera, get_target, .timeout = 5)
{
    Gui::UserCamera cam;

    cr_assert_eq(cam.getTarget().x, 0.0f);
    cr_assert_eq(cam.getTarget().y, 2.0f);
    cr_assert_eq(cam.getTarget().z, 0.0f);
}

Test(UserCamera, set_target, .timeout = 5)
{
    Gui::UserCamera cam;

    cam.setTarget((Vector3){1.0f, 1.0f, 1.0f});

    cr_assert_eq(cam.getTarget().x, 1.0f);
    cr_assert_eq(cam.getTarget().y, 1.0f);
    cr_assert_eq(cam.getTarget().z, 1.0f);
}

Test(UserCamera, get_up, .timeout = 5)
{
    Gui::UserCamera cam;

    cr_assert_eq(cam.getUp().x, 0.0f);
    cr_assert_eq(cam.getUp().y, 1.0f);
    cr_assert_eq(cam.getUp().z, 0.0f);
}

Test(UserCamera, set_up, .timeout = 5)
{
    Gui::UserCamera cam;

    cam.setUp((Vector3){1.0f, 1.0f, 1.0f});

    cr_assert_eq(cam.getUp().x, 1.0f);
    cr_assert_eq(cam.getUp().y, 1.0f);
    cr_assert_eq(cam.getUp().z, 1.0f);
}

Test(UserCamera, get_fovy, .timeout = 5)
{
    Gui::UserCamera cam;

    cr_assert_eq(cam.getFovy(), 70.0f);
}

Test(UserCamera, set_fovy, .timeout = 5)
{
    Gui::UserCamera cam;

    cam.setFovy(1.0f);

    cr_assert_eq(cam.getFovy(), 1.0f);
}

Test(UserCamera, get_cam, .timeout = 5)
{
    Gui::UserCamera cam;

    cr_assert_eq(cam.getCamera()->fovy, 70.0f);
}

Test(UserCamera, setType, .timeout = 5)
{
    Gui::UserCamera cam;

    cam.setType(Gui::UserCamera::FREE);

    cr_assert_eq(cam.getType(), Gui::UserCamera::FREE);
}

Test(UserCamera, setPlayerId, .timeout = 5)
{
    Gui::UserCamera cam;

    cam.setPlayerId(1);

    cr_assert_eq(cam.getPlayerId(), 1);
}
