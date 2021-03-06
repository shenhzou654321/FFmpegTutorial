//
//  MRVideoToPicture.h
//  FFmpegTutorial
//
//  Created by qianlongxu on 2020/6/2.
//

/*
 关键帧的位置大多是不固定的，除非是 mpeg-dash 的视频；
 因此根据设定的 frameInterval 去快进视频流，查找下一个关键帧时，可能出现回退，程序需要处理这个问题；
 因此不同的视频，导出图片的速度是不一样的！
 */

#import <Foundation/Foundation.h>
#import "FFPlayerHeader.h"
#import <CoreGraphics/CGImage.h>

NS_ASSUME_NONNULL_BEGIN

//videoOpened info's key
typedef NSString * const kMRMovieInfoKey;
//视频时长；单位s
FOUNDATION_EXPORT kMRMovieInfoKey kMRMovieDuration;
//视频格式
FOUNDATION_EXPORT kMRMovieInfoKey kMRMovieFormat;
//视频宽；单位像素
FOUNDATION_EXPORT kMRMovieInfoKey kMRMovieWidth;
//视频高；单位像素
FOUNDATION_EXPORT kMRMovieInfoKey kMRMovieHeight;

@class MRVideoToPicture;
@protocol MRVideoToPictureDelegate <NSObject>

@optional
- (void)vtp:(MRVideoToPicture*)vtp videoOpened:(NSDictionary <kMRMovieInfoKey,id> *)info;
- (void)vtp:(MRVideoToPicture*)vtp convertAnImage:(CGImageRef)img;
- (void)vtp:(MRVideoToPicture*)vtp convertFinished:(NSError *)err;

@end

@interface MRVideoToPicture : NSObject

///播放地址
@property (nonatomic, copy) NSString *contentPath;
///期望的像素格式
@property (nonatomic, assign) MRPixelFormatMask supportedPixelFormats;
@property (nonatomic, weak) id <MRVideoToPictureDelegate> delegate;
///期望帧间隔时长
@property (nonatomic, assign) int perferInterval;
///总张数
@property (nonatomic, assign) int maxCount;
@property (nonatomic, assign, readonly) int frameCount;
///准备
- (void)prepareToPlay;
///读包
- (void)readPacket;
///停止读包
- (void)stop;
///m/n 缓冲情况
- (NSString *)peekPacketBufferStatus;

@end

NS_ASSUME_NONNULL_END
