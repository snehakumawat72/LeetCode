class Solution {
public:
    bool isValid(string word) {
        // Check condition 1: minimum 3 characters
        if (word.length() < 3) {
            return false;
        }
        
        bool hasVowel = false;
        bool hasConsonant = false;
        
        // Check each character
        for (char c : word) {
            // Check condition 2: only digits and English letters
            if (!isalnum(c)) {
                return false;
            }
            
            // If it's a letter, check if it's vowel or consonant
            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || 
                    lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }
        
        // Check conditions 3 and 4: at least one vowel and one consonant
        return hasVowel && hasConsonant;
    }
};
