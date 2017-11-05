#include <vector>
#include "scene.h"

Scene::~Scene()
{
  for (std::vector<IObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
    delete(*it);
}
void Scene::operator +=(IObject *obj)
{
  Scene::objects.push_back(obj);
}
void Scene::Draw()
{
  for (std::vector<IObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
    (*it)->Draw();
}
void Scene::Update(double time, double dt)
{
  for (std::vector<IObject *>::iterator it = objects.begin(); it != objects.end(); ++it)
    (*it)->Update(time, dt);
}

