//
// Created by asuna on 3/6/2020.
//

#ifndef ENGINE_CONFIG_HPP
#define ENGINE_CONFIG_HPP


struct Config {
  const char* title = "ENGINE_1.0";
  unsigned width = 800;
  unsigned height = 600;
  unsigned frameLimit = 60;
  bool isFullScreen = false;
  bool vSync = true;
};

extern Config gConfig;

#endif //ENGINE_CONFIG_HPP
