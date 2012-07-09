/* ASEPRITE
 * Copyright (C) 2001-2012  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef UTIL_RENDER_H_INCLUDED
#define UTIL_RENDER_H_INCLUDED

#include "app/color.h"
#include "raster/frame_number.h"

class Document;
class Image;
class Layer;
class Palette;
class Sprite;

class RenderEngine
{
public:

  //////////////////////////////////////////////////////////////////////
  // Checked background configuration

  enum CheckedBgType { CHECKED_BG_16X16,
                       CHECKED_BG_8X8,
                       CHECKED_BG_4X4,
                       CHECKED_BG_2X2 };

  static void loadConfig();
  static CheckedBgType getCheckedBgType();
  static void setCheckedBgType(CheckedBgType type);
  static bool getCheckedBgZoom();
  static void setCheckedBgZoom(bool state);
  static Color getCheckedBgColor1();
  static void setCheckedBgColor1(const Color& color);
  static Color getCheckedBgColor2();
  static void setCheckedBgColor2(const Color& color);

  //////////////////////////////////////////////////////////////////////
  // Preview image

  static void setPreviewImage(Layer* layer, Image* drawable);

  //////////////////////////////////////////////////////////////////////
  // Main function used by sprite-editors to render the sprite

  static Image* renderSprite(const Document* document,
                             const Sprite* sprite,
                             int source_x, int source_y,
                             int width, int height,
                             FrameNumber frame, int zoom,
                             bool draw_tiled_bg);

  //////////////////////////////////////////////////////////////////////
  // Extra functions

  static void renderCheckedBackground(Image* image,
                                      int source_x, int source_y,
                                      int zoom);

  static void renderImage(Image* rgb_image, Image* src_image, const Palette* pal,
                          int x, int y, int zoom);

private:
  static void renderLayer(const Document* document,
                          const Sprite* sprite,
                          const Layer* layer,
                          Image* image,
                          int source_x, int source_y,
                          FrameNumber frame, int zoom,
                          void (*zoomed_func)(Image*, const Image*, const Palette*, int, int, int, int, int),
                          bool render_background,
                          bool render_transparent);
};

#endif
