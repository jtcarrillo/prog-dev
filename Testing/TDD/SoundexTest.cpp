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
    EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
    EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
}
