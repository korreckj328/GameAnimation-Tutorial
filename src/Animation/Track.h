//
// Created by Jeremiah Korreck on 4/23/21.
//

#ifndef GAMEANIMATION_TUT_TRACK_H
#define GAMEANIMATION_TUT_TRACK_H

#include <vector>
#include "Frame.h"
#include "Interpolation.h"
#include <glm/glm.hpp>

template<typename T, int N>
class Track {
protected:
    std::vector<Frame<N>> mFrames;
    Interpolation mInterpolation;
    T SampleConstant(float time, bool looping);
    T SampleLinear(float time, bool looping);
    T SampleCubic(float time, bool looping);
    T Hermite(float time, const T& p1, const T& s1, const T& p2, const T& s2);
    int FrameIndex(float time, bool looping);
    float AdjustTimeToFitTrack(float t, bool loop);
    T Cast(float* value); // will be specialized
public:
    Track();
    void Resize(unsigned int size);
    unsigned int Size();
    Interpolation GetInterpolation();
    void SetInterpolation(Interpolation interp);
    float GetStartTime();
    float GetEndTime();
    T Sample(float time, bool looping);
    Frame<N>& operator[](unsigned int index);
};

typedef Track<float, 1> ScalarTrack;
typedef Track<glm::vec3, 3> VectorTrack;
typedef Track<glm::quat, 4> QuaternionTrack;
#endif //GAMEANIMATION_TUT_TRACK_H
