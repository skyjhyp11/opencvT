//#pragma once
//#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp> //调用cvtColor()


//#include <opencv2\opencv.hpp>

//C++中成员函数在类里面定义和在类外定义有什么区别:
//在类里定义时，这种函数会被编译器编译成内联函数，在类外定义的函数则不会。
//内联函数的好处是加快程序的运行速度，缺点是会增加程序的尺寸。
//比较推荐的写法是把一个经常要用的而且实现起来比较简单的小型函数放到类里去定义，大型函数最好还是放到类外定义。

class ColorDetector
{
private:
	int minDist;//最小可接受距离（像素差值）
	cv::Vec3b target;//目标色  cv命名空间中的三维向量类型 Vec3b
	cv::Mat result;//结果图像() 使用原始的BGR颜色空间 
	cv::Mat converted;//使用Lab颜色空间
public:
	//ColorDetector();

    ColorDetector() : minDist(100)//构造器 此处来实现 cpp中不用再实现
						//初始化 默认距离100 目标色
	{
		target[0] = target[1] = target[2] = 0;
	}


	~ColorDetector();
	int getDistance(const cv::Vec3b &color) const; //获取与目标色之间的距离
	cv::Mat  process(const cv::Mat &image);//处理过程  

	void setColorDistanceThreshold(int distance) //设置距离函数
	{
		{
			if (distance < 0)
			{
				distance = 0;
			}
			minDist = distance;
		}   //声明时 直接定义

	}

	int getColorDistanceThreshold() const //获取距离函数
	{
		return minDist;
	}

	void setTargetColor(unsigned char red, unsigned char green, unsigned char blue) 
	 //设置目标色函数1
	{
        ///1.使用BGR颜色空间
        target[0] = blue;
        target[1] = green;
        target[2] = red;

		//2.使用Lab颜色空间 在process中也需要改变成lab色彩空间

        //cv::Mat tmp(1,1,CV_8UC3);//定义1px像素存放色彩设定值BGR
        //tmp.at<cv::Vec3b>(0, 0)[0] = blue;
        //tmp.at<cv::Vec3b>(0, 0)[1] = green;
        //tmp.at<cv::Vec3b>(0, 0)[2] = red;
        //cv::cvtColor(tmp,tmp,CV_BGR2Lab);
        //target = tmp.at<cv::Vec3b>(0,0);
	}

	void setTargetColor(cv::Vec3b color) //设置目标色函数2 重载
	{
		target = color;
	}

	cv::Vec3b getTargetColor()//获取目标色 //小型函数定义到类里面
	{
		return target;
	}
};

