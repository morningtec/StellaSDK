## StellaSDK2 Release Notes

### Stella SDK r2.3_8f2b1 release notes

* UIKit framework switch to ES2 (StellaKit)
* Screen mode switching (StellaKit, StellaGraphics)
* Xcgen es1 model deprecated in r2.3, can support es2 only(xcgen)
* Xcgen mac project backport to iOS project with --backport (xcgen)
* Feature sample with back button (samples)
* Added docs regarding screen mode switching (StellaKit,StellaGraphics)
* Added a Java view to the Feature sample (samples)
* Added docs which introduce the usage of BackButton (samples)
* Added docs introducing how to add a Java View to Stella app (samples)
* Added cocos2dV2 game MonkeyJump sample(samples)
* Added doc regarding creating a monkeyjump game with Stella SDK from scratch (samples)
* Added UIKit app UICatalog sample(samples)
* Added GLES2Sample as getting-started-guide sample.(samples)
* Supported xcode5 (stella-clang,docs)

### Stella SDK r2.2_b2175 release notes

* Added BillingSDK, which uses java to send SMS billing requests (BillingSDK)
* Added docs in JNIHelper describing usage of BillingSDK (BillingSDK)
* Extract android-ndk, android-sdk, samples from Stella SDK to be submodules (installer)

### Stella SDK r2.1_b2160 release notes

 * StellaMedia headermap fix (StellaMedia)
 * CocosDenshion header fix for Cocos2Dv2 (samples)
 * Features sample prepared for updated documentation release (samples)
 * JNIHelper docs added (samples)
 * xcgen iOS project creation mode with --new flag (xcgen)
 * xcgen retains xib files when converting to Android (xcgen)
 * xcgen add gitignors to xcodeproj and -android folder (xcgen)
 * fixed performance issue with font caching (StellaGraphics)
 * fix AVAudioPlayer isPlaying always returning NO (StellaMedia)

### Stella SDK r2.0_b1915 release notes

* massively improved UIKit for app compatibility (StellaKit)
* introduced sibtool to convert xib files to sib files (StellaKit)
* using UI- prefix for StellaKit classes (StellaKit)
* support support for Cocos2Dv2 (OpenGLESv2)
* implicit/explicit animation support (CoreAnimation)
* gesture recognisors support (StellaKit)
* improved xcgen so that iOS build settings are retained (xcgen)
* introduced general purpos stella-config script (scripts)
