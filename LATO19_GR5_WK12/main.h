#pragma once


template<int P, int W, bool neg, bool er10>
class MyPower{
public:
    static const double value;
};

template<int P, int W>
class MyPower<P, W, false, false>{
public:
    static const double value;
};

template<int P, int W>
const double MyPower<P, W, false, false>::value = P * MyPower<P, W-1, false, false>::value; 

template<int P>
class MyPower<P, 0, false, false>{
public:
    static const double value;
};

template<int P>
const double MyPower<P, 0, false, false>::value = 1.0;

template<int P>
class MyPower<P, 0, true, false>{
public:
    static const double value;
};

template<int P>
const double MyPower<P, 0, true, false>::value = 1.0;


template<int P, int W>
class MyPower<P, W, true, false>{
public:
    static const double value;
};

template<int P, int W>
const double MyPower<P, W, true, false>::value = (1.0/P) * MyPower<P, W+1, true, false>::value; 


template<int P, int W>
class MyPower<P, W, false, true>{
public:
    static const double value;
};




template<int P, int W>
class Power{
public:
    static const double value;
};

template<int P, int W>
const double Power<P, W>::value = MyPower<P, W, (W < 0), (W > 10)>::value;