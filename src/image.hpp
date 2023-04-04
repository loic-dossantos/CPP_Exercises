#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>


template <typename P, size_t W, size_t H>
class Image {
    private:
        std::array<std::array<P, W>, H> _array {};

    public:
        Image() = default;

        Image(const P& pix) {
            for(size_t j = 0; j < H; j++) {
                for(size_t i = 0; i < W; i++) {
                    _array[j][i] = pix;
                }
            }
        }

        Image(const std::function<char(const size_t, const size_t)> fun) {
            for(size_t j = 0; j < H; j++) {
                for(size_t i = 0; i < W; i++) {
                    (*this)(i,j) = fun(i,j);
                }
            }
        }

        P& operator()(size_t i, size_t j) { 
            assert(j < H);
            assert(i < W);
            return _array[j][i];
        }

        const P& operator()(size_t i, size_t j) const {
            assert(j < H);
            assert(i < W);
            return _array[j][i];
        }
};

template <typename P, size_t W, size_t H>
Image<P, W, H> operator+(Image<P, W, H> img1, Image<P, W, H> img2) {
    Image img_res = Image<P, W, H>();

    for(size_t j = 0; j < H; j++) {
        for(size_t i = 0; i < W; i++) {
            img_res(i,j) = img1(i,j) + img2(i,j);
        }
    }

    return img_res;
}