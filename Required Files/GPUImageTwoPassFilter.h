#import "GPUImageFilter.h"

@interface GPUImageTwoPassFilter : GPUImageFilter
{
    GLuint secondFilterOutputTexture;

    GLProgram *secondFilterProgram;
    GLint secondFilterPositionAttribute, secondFilterTextureCoordinateAttribute;
    GLint secondFilterInputTextureUniform, secondFilterInputTextureUniform2;
    
    GLuint secondFilterFramebuffer;
    
    NSMutableDictionary *secondProgramUniformStateRestorationBlocks;
}

// Initialization and teardown
- (instancetype)initWithFirstStageVertexShaderFromString:(NSString *)firstStageVertexShaderString firstStageFragmentShaderFromString:(NSString *)firstStageFragmentShaderString secondStageVertexShaderFromString:(NSString *)secondStageVertexShaderString secondStageFragmentShaderFromString:(NSString *)secondStageFragmentShaderString;
- (instancetype)initWithFirstStageFragmentShaderFromString:(NSString *)firstStageFragmentShaderString secondStageFragmentShaderFromString:(NSString *)secondStageFragmentShaderString;
- (void)initializeSecondaryAttributes;
- (void)initializeSecondOutputTextureIfNeeded;

// Managing the display FBOs
- (void)createSecondFilterFBOofSize:(CGSize)currentFBOSize;

@end
