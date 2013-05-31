//---------------------------------------------------------------------------
#include <cassert>
//---------------------------------------------------------------------------
#include "nsanabrosstlheader.h"
//---------------------------------------------------------------------------
int NsanaBrosKeys::m_key_left = 0;
int NsanaBrosKeys::m_key_right = 0;
int NsanaBrosKeys::m_key_up = 0;
int NsanaBrosKeys::m_key_down = 0;
//---------------------------------------------------------------------------
NsanaBrosKeys::NsanaBrosKeys()
  : m_dx(0),
    m_dy(0)

{
}
//---------------------------------------------------------------------------
///GetHortizonal returns the direction in the
///horizontal direction:
///*-1: left key pressed
///*+0: no left or right key pressed
///*+1: right key pressed
int NsanaBrosKeys::GetHorizontal() const
{
  return m_dx;
}
//---------------------------------------------------------------------------
///GetVertical returns the direction in the
///vertical direction:
///*-1: up key pressed
///*+0: no up or down key pressed
///*+1: down key pressed
int NsanaBrosKeys::GetVertical() const
{
  return m_dy;
}
//---------------------------------------------------------------------------
void NsanaBrosKeys::KeyPress(const int key)
{
  m_keys.insert(key);
  if (key == m_key_up)
  {
    this->KeyRelease(m_key_down);
  }
  else if (key == m_key_down)
  {
    this->KeyRelease(m_key_up);
  }
  else if (key == m_key_left )
  {
    this->KeyRelease(m_key_right);
  }
  else if (key == m_key_right)
  {
    this->KeyRelease(m_key_left );
  }
  Update();
}
//---------------------------------------------------------------------------
void NsanaBrosKeys::KeyRelease(const int key)
{
  m_keys.erase(key);
  Update();
}
//---------------------------------------------------------------------------
void NsanaBrosKeys::SetKeyLeft(const int key)
{
  m_key_left = key;
}
//---------------------------------------------------------------------------
void NsanaBrosKeys::SetKeyRight(const int key)
{
  m_key_right = key;
}
//---------------------------------------------------------------------------
void NsanaBrosKeys::SetKeyUp(const int key)
{
  m_key_up = key;
}
//---------------------------------------------------------------------------
void NsanaBrosKeys::SetKeyDown(const int key)
{
  m_key_down = key;
}
//---------------------------------------------------------------------------
//double NsanaBrosKeys::StealDx()
//{
//  double dx = m_dx;
//  m_dx = 0.0;
//  return dx;
//}
//---------------------------------------------------------------------------
//double NsanaBrosKeys::StealDy()
//{
//  double dy = m_dy;
//  m_dy = 0.0;
//  return dy;
//}
//---------------------------------------------------------------------------
void NsanaBrosKeys::Update()
{
  m_dx = 0;
  m_dy = 0;
  if (m_keys.count(m_key_up))
  {
    m_dy = -1;
  }
  else if (m_keys.count(m_key_down))
  {
    m_dy = 1;
  }
  if (m_keys.count(m_key_left))
  {
    m_dx = -1;
  }
  else if (m_keys.count(m_key_right))
  {
    m_dx = 1;
  }
}
//---------------------------------------------------------------------------

