#include "../include/Message.h"

Message::Message()
{
    this->message = Model <Obj> ("models/message.obj", 0.0, 1.0, 1.0);

    message.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.6f)));
    message.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.7f, -1.5f)));
}

void Message::draw(GLuint programID, glm::mat4 camera, bool status)
{
    if(status)
        this->message.draw(programID, camera);
}
