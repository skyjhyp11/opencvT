//#pragma once
#include "ColorDetector.h"
class ColorDetectController
{
private:
    static ColorDetectController *singleton;// dantimoshi
    ColorDetector *cdetect;//可以多种方法detect Controller的作用在与此
	cv::Mat image;
	cv::Mat result;

	//构造器
	ColorDetectController()
	{
		cdetect = new ColorDetector();//初始化成员变量
	}


public:
	//析构器
	~ColorDetectController()
	{
        delete cdetect;
	}

	void setColorDistanceThreshold(int distance)
	{
		cdetect->setColorDistanceThreshold(distance);//来自"ColorDetector.h"
	}
	int getColorDistanceThreshold() const
	{
		return cdetect->getColorDistanceThreshold();//来自"ColorDetector.h"
	}
	void setTargetColor(unsigned char red, unsigned char green, unsigned char blue)
		//设置目标色函数1
	{
		cdetect->setTargetColor(red,green,blue);//来自"ColorDetector.h"
	}
	//void ?  cv::Vec3b //注意是 &red
	void getTargetColor(unsigned char &red, unsigned char &green, unsigned char &blue)const//获取目标色 //小型函数定义到类里面
	{
		cv::Vec3b color = cdetect->getTargetColor();//来自"ColorDetector.h"
		red = color[2];
		green = color[1];
		blue = color[0];

		//return color;
	}
	bool setInputImage(std::string filename)
	{
		image = cv::imread(filename);
		if (!image.data)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

    bool setInputImage(cv::Mat img)
    {
        ////image = cv::imread(filename);
        //if (!image.data)
        //{
         //   return false;
        //}
        //else
       // {
            image=img;
           return true;
        //}
    }

	const cv::Mat getInputImage() const
	{
		return image;
	}

	void process()//处理图像函数
	{
		result = cdetect->process(image);
	}
	const cv::Mat getLastResult() const
	{
		return result;
	}

    static ColorDetectController *getInstance()
    {
        //首次调用时创建实例
        if(singleton==0)
           singleton=new ColorDetectController;

        return singleton;

    }
    //释放单体实例
    static void destroy()
    {
        if(singleton!=0)
        {
            delete singleton;
            singleton=0;
        }
    }


};

