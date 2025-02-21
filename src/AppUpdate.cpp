#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"


void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        float x = m_Giraffe->GetPosition().x;
        float y = m_Giraffe->GetPosition().y;
        m_Giraffe->SetPosition({x, y + 10});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        float x = m_Giraffe->GetPosition().x;
        float y = m_Giraffe->GetPosition().y;
        m_Giraffe->SetPosition({x - 10, y});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        float x = m_Giraffe->GetPosition().x;
        float y = m_Giraffe->GetPosition().y;
        m_Giraffe->SetPosition({x, y - 10});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        float x = m_Giraffe->GetPosition().x;
        float y = m_Giraffe->GetPosition().y;
        m_Giraffe->SetPosition({x + 10, y});
    }


    if (m_Phase == Phase::COLLIDE_DETECTION) {
        m_Giraffe->IfCollides(m_Chest) ? m_Chest->SetVisible(false) : m_Chest->SetVisible(true);
    }
    if (m_Phase == Phase::OPEN_THE_DOORS) {
        for (auto &door: m_Doors) {
            m_Giraffe->IfCollides(door) ? door->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png")
                                        : door->SetImage(GA_RESOURCE_DIR"/Image/Character/door_close.png");
        }
    }
    if (m_Phase == Phase::COUNTDOWN) {
        m_Ball->SetVisible(true);
        m_Ball->SetLooping(false);
    }
    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
