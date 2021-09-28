#include <string>
#include "SoundexTest.h"
#include <gmock/gmock.h>

// fixture class defined for Google Mock
class SoundexEncoding: public testing::Test{
     public:
          Soundex soundex;};
//reduces ASSERT_THAT(encoded, ::testing::Eq("A000"));} to ASSERT_THAT(encoded, Eq("A000"));}
//using ::testing::Eq;
using namespace testing;

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
     //ASSERT_THAT specific to Google Mock not Google Test
     ASSERT_THAT(soundex.encode("A"), Eq("A000"));}
TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits){
     ASSERT_THAT(soundex.encode("I"), Eq("I000"));}
TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits){
    ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));}
TEST_F(SoundexEncoding, IgnoresNonAlphabetics){
    ASSERT_THAT(soundex.encode("A#"),Eq("A000"));}
TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits){
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));}
TEST_F(SoundexEncoding, LimitsLengthToFourCharacters){
    ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));}
TEST_F(SoundexEncoding, IgnoresVowelLikeLetters){
    ASSERT_THAT(soundex.encode("Baeiouhycdl"),Eq("B234"));}
TEST_F(SoundexEncoding, CombinesDuplicateEncodings){
    ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
    ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
    ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));
    ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}
TEST_F(SoundexEncoding, DISABLED_DisableExample){
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));}

