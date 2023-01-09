//
//  ListVideoCell.h
//  TXLiteAVDemo
//
//  Created by annidyfeng on 2018/1/25.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SuperPlayer.h"
#import "TXMoviePlayInfoResponse.h"

@interface ListVideoUrl : NSObject
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *url;
@end

@interface DynamicWaterModel : NSObject
@property(nonatomic, assign) CGFloat  textFont;
@property(nonatomic, strong) NSString *dynamicWatermarkTip;
@property(nonatomic, strong) UIColor  *textColor;
@end

@interface SuperPlayerSubtitles : NSObject
/// 字幕地址
@property (nonatomic, strong) NSString *subtitlesUrl;
/// 字幕名称
@property (nonatomic, strong) NSString *subtitlesName;
/// 字幕类型
@property (nonatomic, assign) NSInteger subtitlesType;
@end

@interface ListVideoModel : NSObject
@property(nonatomic, strong) NSString *coverUrl;
@property(nonatomic, strong) NSString *customCoverUrl;
@property(nonatomic, assign) int       duration;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, assign) NSInteger appId;
@property(nonatomic, strong) NSString *fileId;
@property(nonatomic, strong) NSString *url;
@property(nonatomic, strong) NSArray<ListVideoUrl *> *hdUrl;
@property(nonatomic, assign) int type;  // 0 - 点播；1 - 直播
@property(nonatomic, strong) NSString *psign;
@property(nonatomic, strong) DynamicWaterModel *dynamicWaterModel;
@property(nonatomic, assign) int playAction; // 0 - 自动播放；1 - 手动播放  2 - 预加载
@property(nonatomic, assign) BOOL isEnableCache;  // 是否启用缓存模块
@property(nonatomic, strong) NSMutableArray<SuperPlayerSubtitles *> *subtitlesArray;  // 需要加载的字幕数组
- (void)addHdUrl:(NSString *)url withTitle:(NSString *)title;
- (void)setModel:(SuperPlayerModel *)model;
- (SuperPlayerModel *)getPlayerModel;
@end

@interface ListVideoCell : UITableViewCell

- (void)setDataSource:(ListVideoModel *)source;
- (SuperPlayerModel *)getPlayerModel;
- (ListVideoModel *)getSource;
@end
