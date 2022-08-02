#include <iostream>
#include <vector>
#include <random>
using namespace std;

struct Kanji{
    string kanji;
    bool was_shown;

    Kanji(string k, bool s) : kanji{k}, was_shown{s} {}
};

const int Overall_size = 48;
Kanji kanji[Overall_size] = {{"盾", false}, {"勇", false}, {"信", false}, {"誰", false}, {"恥", false}, {"氏", false}, {"真", false}, {"快", false}, {"適", false}, {"仕", false}, {"欲", false}, {"昨", false}, {"付", false}, {"号", false}, {"鉄", false}, {"失", false}, {"油", false}, {"昭", false}, {"植", false}, {"宿", false}, {"薬", false}, {"医", false}, {"習", false}, {"倍", false}, {"洋", false}, {"旅", false}, {"服", false}, {"以", false}, {"別", false}, {"特", false}, {"建", false}, {"試", false}, {"験", false}, {"借", false}, {"堂", false}, {"質", false}, {"貸", false}, {"発", false}, {"業", false}, {"代", false}, {"動", false}, {"題", false}, {"度", false}, {"院", false}, {"重", false}, {"集", false}, {"物", false}, {"品", false}};
const string readings[Overall_size] = {"ジュン・たて", "ユウ・いさ.む", "シン", "スイ・だれ・たれ・た", "チ・は.じる・はじ・は.じらう・は.ずかしい", "シ・うじ・~うじ", "シン・ま・ま~・まこと", "カイ・こころよ.い", "テキ・かな.う", "シ・ジ・つか.える", "ヨク・ほっ.する・ほ.しい", "サク", "フ・つ.ける・~つ.ける・~づ.ける・つ.け・つ.け~・~つ.け・~づ.け・~づけ・つ.く・~づ.く・つ.き・~つ.き・~つき・~づ.き・~づき", "ゴウ・さけ.ぶ・よびな", "テツ・くろがね", "シツ・うしな.う・う.せる", "ユ・ユウ・あぶら", "ショウ", "ショク・う.える・う.わる", "シュク・やど・やど.る・やど.す", "ヤク・くすり", "イ・い.やす・い.する・くすし", "シュウ・ジュ・なら.う・なら.い", "バイ", "ヨウ", "リョ・たび", "フク", "イ・もっ.て", "ベツ・わか.れる・わ.ける", "トク", "ケン・コン・た.てる・た.て・~だ.て・た.つ", "シ・こころ.みる・ため.す", "ケン・ゲン・あかし・しるし・ため.す・ためし", "シャク・か.りる", "ドウ", "シツ・シチ・チ・たち・ただ.す・もと・わりふ", "タイ・か.す・か.し~・かし~", "ハツ・ホツ・た.つ・あば.く・おこ.る・つか.わす・はな.つ", "ギョウ・ゴウ・わざ", "ダイ・タイ・か.わる・かわ.る・かわ.り・か.わり・~がわ.り・~が.わり・か.える・よ・しろ", "ドウ・うご.く・うご.かす", "ダイ", "ド・ト・タク・たび・~た.い", "イン", "ジュウ・チョウ・え・おも.い・おも.り・おも.なう・かさ.ねる・かさ.なる・おも", "シュウ・あつ.まる・あつ.める・つど.う", "ブツ・モツ・もの・もの~", "ヒン・ホン・しな"};
const string meanings[Overall_size] = {"shield; escutcheon; pretext", "courage; cheer up; be in high spirits; bravery; heroism", "faith; truth; fidelity; trust", "who; someone; somebody", "shame; dishonor", "family name; surname; clan", "true; reality; Buddhist sect", "cheerful; pleasant; agreeable; comfortable", " suitable; occasional; rare; qualified; capable", "attend; doing; official; serve", "longing; covetousness; greed; passion; desire; craving", "yesterday; previous", "adhere; attach; refer to; append", "nickname; number; item; title; pseudonym; name; call", "iron", "lose; error; fault; disadvantage; loss", "oil; fat", "shining; bright", "plant", "inn; lodging; relay station; dwell; lodge; be pregnant; home; dwelling", "medicine; chemical; enamel; gunpowder; benefit", "doctor; medicine", "learn", "double; twice; times; fold", "ocean; sea; foreign; Western style", "trip; travel", "clothing; admit; obey; discharge", "by means of; because; in view of; compared with", "separate; branch off; diverge; fork; another; extra; specially", "special", "build", "test; try; attempt; experiment; ordeal", "verification; effect; testing", "borrow; rent", "public chamber; hall", "substance; quality; matter; temperament", "lend", "departure; discharge; publish; emit; start from; disclose; counter for gunshots", "business; vocation; arts; performance", "substitute; change; convert; replace; period; age; counter for decades of ages, eras, etc.; generation; charge; rate; fee ", "move; motion; change; confusion; shift; shake", "topic; subject", "degrees; occurrence; time; counter for", "Inst.; institution; temple; mansion; school", "heavy; important; esteem; respect; heap up; pile up; nest of boxes; -fold", "gather; meet; congregate; swarm; flock", "thing; object; matter", "goods; refinement; dignity; article; counter for meal courses"};
string str;

bool flash_cards(int randomNumber, vector<int>& forgotten, int num, bool& go_to_forgotten, bool& new_forgotten){
    

    cout << "\n█▄▀ ▄▀█ █▄░█ ░░█ █   █▀▀ █░░ ▄▀█ █▀ █░█   █▀▀ ▄▀█ █▀█ █▀▄ █▀\n" << 
              "█░█ █▀█ █░▀█ █▄█ █   █▀░ █▄▄ █▀█ ▄█ █▀█   █▄▄ █▀█ █▀▄ █▄▀ ▄█\n\n" << std::endl;

    cout << num << ". " << kanji[randomNumber].kanji << ' ';
    
    while(getline(cin, str)){
        for (int i = 0; i < str.length(); i++){
            str[i] = tolower(str[i]);
        }

        if(str.empty()){
            cout<< "----------" << '\n';
            cout << "readings: " << readings[randomNumber] << '\n';
            cout << "meanings: " << meanings[randomNumber] << "\n";

            while(getline(cin, str)){
                for (int i = 0; i < str.length(); i++){
                    str[i] = tolower(str[i]);
                }

                if(str.empty()){
                    system("clear");
                    return false;

                } else if (str == "e"){
                    return true;

                } else if (str != "q" && str != "e" && !str.empty()){
                    forgotten.push_back(randomNumber);
                    system("clear");
                    new_forgotten = true;
                    return false;
                } else if (str == "q"){
                    system("clear");
                    go_to_forgotten = true;
                    return false;
                }
            }  
             
        } else if (str == "e"){
            return true;

        } else if (str != "q" && str != "e" && !str.empty()){
            forgotten.push_back(randomNumber);
            system("clear");
            new_forgotten = true;
            return false;

        } else if (str == "q"){
            system("clear");
            go_to_forgotten = true;
            return false;
        }

    } 

    return false;
}

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, Overall_size - 1);

    bool go_to_forgotten = false, new_forgotten = false;
    int randomNumber, num = 1;

    vector<int> forgotten;
    vector<int> next_round;

    while(num <= Overall_size){
        randomNumber = distr(gen);

        if(kanji[randomNumber].was_shown != true){
            kanji[randomNumber].was_shown = true;

            if(flash_cards(randomNumber, forgotten, num, go_to_forgotten, new_forgotten)){
                return 0;
            } 
            if(go_to_forgotten && forgotten.size() != 0){
                break;
            }
            num++;
            
        }

    }
    
    while(true){
        if(forgotten.size() == 0 && next_round.size() == 0){
            cout << "You did everything, congratulations:D" << "\n";
            while(getline(cin, str)){
                if(str.empty()){
                    system("clear");
                    return 0;
                }
            } 
        } else {
            cout << "Wait... you forgot some? Lets try again then";
            int y = forgotten.size();
            
            for(int i = 0; i < y; i++){
                go_to_forgotten = false;
                randomNumber = forgotten.back();

                if(flash_cards(randomNumber, forgotten, i + 1, go_to_forgotten, new_forgotten)){
                    return 0;
                } 
                if(new_forgotten){
                    next_round.push_back(forgotten.back());
                    forgotten.pop_back();
                }
                new_forgotten = false;
                forgotten.pop_back();
                
                
            }
            while(next_round.size() != 0){
                forgotten.push_back(next_round.back());
                next_round.pop_back();
            }
        }
    }
      
    return 0;
}