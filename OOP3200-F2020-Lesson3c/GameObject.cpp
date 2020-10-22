#include "GameObject.h"

GameObject::GameObject(): m_id(0), m_name("unknown"), m_position(Vector2D<float>())
{
}

GameObject::GameObject(const int id, const float x, const float y)
{
	SetID(id);
	SetName("Not set");
	SetPosition(x, y);
}

GameObject::GameObject(const int id, const Vector2D<float>& position)
{
	SetID(id);
	SetName("Not set");
	SetPosition(position);
}

GameObject::GameObject(const std::string name, const int id, const float x, const float y)
{
	SetID(id);
	SetName(name);
	SetPosition(x, y);
}

GameObject::GameObject(std::string name, const int id, const Vector2D<float>& position)
{
	SetID(id);
	SetName(name);
	SetPosition(position);
}

GameObject::~GameObject()
= default;

GameObject::GameObject(const GameObject& other_object)
{
	SetID(other_object.m_id);
	SetPosition(other_object.m_position);
}

GameObject& GameObject::operator=(const GameObject& other_object)
{
	SetID(other_object.m_id);
	SetPosition(other_object.m_position);
	return (*this);
}

Vector2D<float> GameObject::GetPosition() const
{
	return m_position;
}

int GameObject::GetID() const
{
	return m_id;
}

std::string GameObject::GetName() const
{
	return m_name;
}

void GameObject::SetID(const int id)
{
	m_id = id;
}

void GameObject::SetName(const std::string& name)
{
	m_name = name;
}

void GameObject::SetPosition(const float x, const float y)
{
	m_position.Set(x, y);
}

void GameObject::SetPosition(const Vector2D<float>& new_position)
{
	m_position = new_position;
}

std::string GameObject::ToString() const
{
	std::string output_string;
	output_string += "ID       : " + std::to_string(GetID()) + "\n";
	output_string += "Name     : " + GetName() + "\n";
	output_string += "Position : " + GetPosition().ToString() + "\n";
	return output_string;
}

std::string GameObject::ToFile() const
{
	return std::to_string(GetID()) + " " + GetName() + " " + GetPosition().ToString();
}
