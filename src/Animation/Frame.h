//
// Created by jeremiahkorreck on 4/22/21.
//

#ifndef GAMEANIMATION_TUT_FRAME_H
#define GAMEANIMATION_TUT_FRAME_H

// This class is used to store keyframes in an animation track

template<unsigned int N>
class Frame {
public:
    float mValue[N];
    float mIn[N];
    float mOut[N];
    float mTime;
};

typedef Frame<1> ScalarFrame;
typedef Frame<3> VectorFrame;
typedef Frame<4> QuaternionFrame;

#endif //GAMEANIMATION_TUT_FRAME_H
