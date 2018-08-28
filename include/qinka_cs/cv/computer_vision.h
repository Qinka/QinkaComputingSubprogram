#pragma once

#ifndef _CV__COMPUTER_VISION_H_
#define _CV__COMPUTER_VISION_H_

#ifdef __cplusplus
extern "C" {
#endif // ! __cplusplus

void color_background_mask(float *out, float *in, float *img_bg_color, int n, int en);
void color_background_mask_rgb_rang(float *out, float *in, int n,
                                    float aR, float aG, float aB,
                                    float bR, float bG, float bB);

void color_rgb_to_hsv(float *out, float *in, int n);
void color_hsv_to_rgb(float *out, float *in, int n);

#ifdef __cplusplus
}
#endif // ! __cplusplus

#endif // !_CV__COMPUTER_VISION_H_