//
//  AppDelegate.m
//  FFmpegTutorial-macOS
//
//  Created by Matt Reach on 2020/11/18.
//

#import "AppDelegate.h"
#import "NSNavigationController.h"
#import "RootViewController.h"

@interface AppDelegate ()

@property (nonatomic, strong) NSWindowController *rootWinController;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    NSWindow *window = [[NSWindow alloc] initWithContentRect:CGRectZero styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable backing:NSBackingStoreBuffered defer:YES];
    window.title = @"FFmpeg学习教程";
    window.titleVisibility = NSWindowTitleHidden;
    window.titlebarAppearsTransparent = YES;
    window.styleMask |= NSWindowStyleMaskFullSizeContentView;
    [window setMinSize:CGSizeMake(300, 300)];
    
    NSWindowController *rootWinController = [[NSWindowController alloc] initWithWindow:window];
    
    RootViewController *rootViewController = [[RootViewController alloc] init];
    
    NSNavigationController *navController = [[NSNavigationController alloc] initWithRootViewController:rootViewController];
    navController.title = @"FFmpeg-Tutorial";
    window.contentViewController = navController;
    [window center];
    [window makeKeyWindow];
    [rootWinController showWindow:nil];
    
    self.rootWinController = rootWinController;
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
