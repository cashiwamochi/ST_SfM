#pragma once

#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

#include "Tracker.h"
#include "Mapper.h"
#include "LoopClosure.h"
#include "KPExtractor.h"
#include "Matcher.h"

namespace TS_SfM {

  struct SystemConfig {
    std::string str_path_to_images; 
  };

  struct Camera {
    float f_cx;
    float f_cy;
    float f_fx;
    float f_fy;
    float f_k1;
    float f_k2;
    float f_p1;
    float f_p2;
    float f_k3;
  };

  namespace ConfigLoader {
    std::pair<SystemConfig, Camera> LoadConfig(const std::string str_config_file);
    std::vector<std::string> ReadImagesInDir(const std::string& path_to_images);
    cv::Mat LoadImage(const std::string str_image_name);
    Tracker::TrackerConfig LoadTrackerConfig(const std::string str_config_file);
    Mapper::MapperConfig LoadMapperConfig(const std::string str_config_file);
    LoopClosure::LoopConfig LoadLoopConfig(const std::string str_config_file);
    KPExtractor::ExtractorConfig LoadExtractorConfig(const std::string str_config_file);
    Matcher::MatcherConfig LoadMatcherConfig(const std::string str_config_file);
    void LoadInitializerConfig(int& num_frames, int& connect_distance, const std::string str_config_file);
  }
}
