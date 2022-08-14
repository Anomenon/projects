#include <iostream>
#include <vector>
using namespace std;

struct Kanji
{
    string kanji;
    string readings;
    string meanings;
    bool was_shown;

};
int const SIZE = 75;
int num = 1;
int num_of_forgotten = 0;

Kanji kanji_data[SIZE] = {{"怖", "フ・ホ・こわ.い・こわ.がる・お.じる・おそ.れる", "dreadful; befrightened; fearful", false}, {"忙", "ボウ・モウ・いそが.しい・せわ.しい・おそ.れる・うれえるさま", "busy; occupied; restless", false}, {"靴", "カ・くつ", "shoes", false}, {"偶", "グウ・たま", "accidentally; evennumber; couple; man&wife; samekind", false}, {"偉", "イ・えら.い", "admirable; greatness; remarkable; conceited; famous; excellent", false}, {"幾", "キ・いく~・いく.つ・いく.ら", "howmany; howmuch; howfar; howlong; some; several", false}, {"疑", "ギ・うたが.う", "doubt; distrust; besuspicious; question", false}, {"供", "キョウ・ク・クウ・グ・そな.える・とも・~ども", "submit; offer; present; serve(meal); accompany", false}, {"割", "カツ・わ.る・わり・わ.り・わ.れる・さ.く", "proportion; comparatively; divide; cut; separate; split", false}, {"優", "ユウ・ウ・やさ.しい・すぐ.れる・まさ.る", "tenderness; excel; surpass; actor; superiority; gentleness", false}, {"収", "シュウ・おさ.める・おさ.まる", "income; obtain; reap; pay; supply; store", false}, {"宅", "タク", "home; house; residence; ourhouse; myhusband", false}, {"貰", "セイ・シャ・もら.う", "get; have; obtain", false}, {"警", "ケイ・いまし.める", "admonish; commandment", false}, {"与", "ヨ・あた.える・あずか.る・くみ.する・ともに", "bestow; participate in; give; award; impart; provide; cause; gift; godsend", false}, {"渡", "ト・わた.る・~わた.る・わた.す", "transit; ford; ferry; cross; import; deliver; diameter; migrate", false}, {"突", "トツ・カ・つ.く", "stab; protruding; thrust; pierce; prick; collision; sudden", false}, {"捕", "ホ・と.らえる・と.らわれる・と.る・とら.える・とら.われる・つか.まえる・つか.まる", "catch; capture", false}, {"迎", "ゲイ・むか.える", "welcome; meet; greet", false}, {"舞", "ブ・ま.う・~ま.う・まい", "dance; flit; circle; wheel", false}, {"頼", "ライ・たの.む・たの.もしい・たよ.る", "trust; request", false}, {"途", "ト・みち", "route; way; road", false}, {"婚", "コン", "marriage", false}, {"結", "ケツ・ケチ・むす.ぶ・ゆ.う・ゆ.わえる", "tie; bind; contract; join; organize; do up hair; fasten", false}, {"浮", "フ・う.く・う.かれる・う.かぶ・む・う.かべる", "floating; float; rise to surface", false}, {"押", "オウ・お.す・お.し~・お.っ~・お.さえる・おさ.える", "push; stop; check; subdue; attach; seize; weight; shove; press; seal; do in spite of", false}, {"神", "シン・ジン・かみ・かん~・こう~", "gods; mind; soul", false}, {"倒", "トウ・たお.れる・~だお.れ・たお.す・さかさま・さかさ・さかしま", "overthrow; fall; collapse; drop; break down", false}, {"抱", "ホウ・だ.く・いだ.く・かか.える", "embrace; hug; hold in arms", false}, {"恐", "キョウ・おそ.れる・おそ.る・おそ.ろしい・こわ.い・こわ.がる", "fear; dread; awe", false}, {"戻", "レイ・もど.す・もど.る", "re-; return; revert; resume; restore; go backwards", false}, {"越", "エツ・オツ・こ.す・~こ.す・~ご.し・こ.える・~ご.え", "surpass; cross over; move to; exceed; Vietnam", false}, {"勤", "キン・ゴン・つと.める・~づと.め・つと.まる・いそ.しむ", "diligence; become employed; serve", false}, {"困", "コン・こま.る", "quandary; become distressed; annoyed", false}, {"刻", "コク・きざ.む・きざ.み", "engrave; cut fine; chop; hash; mince; time; carving", false}, {"痛", "ツウ・いた.い・いた.む・いた.ましい・いた.める", "pain; hurt; damage; bruise", false}, {"探", "タン・さぐ.る・さが.す", "grope; search; look for", false}, {"暮", "ボ・く.れる・く.らす", "evening; twilight; season's end; livelihood; make a living; spend time", false}, {"温", "オン・あたた.か・あたた.かい・あたた.まる・あたた.める・ぬく", "warm", false}, {"泉", "セン・いずみ", "spring; fountain", false}, {"恋", "レン・こ.う・こい・こい.しい", "romance; in love; yearn for; miss; darling", false}, {"寒", "カン・さむ.い", "cold", false}, {"冷", "レイ・つめ.たい・ひ.える・ひ.や・ひ.ややか・ひ.やす・ひ.やかす・さ.める・さ.ます", "cool; cold (beer person); chill", false}, {"暑", "ショ・あつ.い", "sultry; hot; summer heat", false}, {"熱", "ネツ・あつ.い", "heat; temperature; fever; mania; passion", false}, {"暖", "ダン・ノン・あたた.か・あたた.かい・あたた.まる・あたた.める", "warmth", false}, {"吸", "キュウ・す.う", "suck; imbibe; inhale; sip", false}, {"忘", "ボウ・わす.れる", "forget", false}, {"洗", "セン・あら.う", "wash; inquire into; probe", false}, {"泳", "エイ・およ.ぐ", "swim", false}, {"窓", "ソウ・ス・まど・てんまど・けむだし", "window; pane", false}, {"腹", "フク・はら", "abdomen; belly; stomach", false}, {"頂", "チョウ・いただ.く・いただき", "place on the head; receive; top of head; top; summit; peak", false}, {"誤", "ゴ・あやま.る・~あやま.る", "mistake; err; do wrong; mislead", false}, {"否", "ヒ・いな・いや", "negate; no; noes; refuse; decline; deny", false}, {"存", "ソン・ゾン・ながら.える・あ.る・たも.つ・と.う", "exist; suppose; be aware of; believe; feel", false}, {"違", "イ・ちが.う・ちが.い・ちが.える・~ちが.える・たが.う・たが.える", "difference; differ", false}, {"訪", "ホウ・おとず.れる・たず.ねる・と.う", "call on; visit; look up; offer sympathy", false}, {"州", "シュウ・ス・す", "state; province", false}, {"訳", "ヤク・わけ", "translate; reason; circumstance; case", false}, {"若", "ジャク・ニャク・ニャ・わか.い・わか~・も.しくわ・も.し・も.しくは・ごと.し", "young; if; perhaps; possibly; low number; immature", false}, {"段", "ダン・タン", "grade; steps; stairs", false}, {"呼", "コ・よ.ぶ", "call; call out to; invite", false}, {"値", "チ・ね・あたい", "price; cost; value", false}, {"処", "ショ・ところ・~こ・お.る", "dispose; manage; deal with; sentence; condemn; act; behave; place", false}, {"所", "ショ・ところ・~ところ・どころ・とこ", "place; extent", false}, {"在", "ザイ・あ.る", "exist; outskirts; suburbs; located in", false}, {"座", "ザ・すわ.る", "squat; seat; cushion; gathering; sit", false}, {"除", "ジョ・ジ・のぞ.く・~よ.け", "exclude; division (x/3); remove; abolish; cancel; except", false}, {"降", "コウ・ゴ・お.りる・お.ろす・ふ.る・ふ.り・くだ.る・くだ.す", "descend; precipitate; fall; surrender", false}, {"危", "キ・あぶ.ない・あや.うい・あや.ぶむ", "dangerous; fear; uneasy", false}, {"亡", "ボウ・モウ・な.い・な.き~・ほろ.びる・ほろ.ぶ・ほろ.ぼす", "deceased; the late; dying; perish", false}, {"更", "コウ・さら・さら.に・ふ.ける・ふ.かす", "grow late; night watch; sit up late; of course; renew; renovate; again; more and more; further", false}, {"払", "フツ・ヒツ・ホツ・はら.う・~はら.い・~ばら.い", "pay; clear out; prune; banish; dispose of", false}, {"背", "ハイ・せ・せい・そむ.く・そむ.ける", "stature; height; back; behind; disobey; defy; go back on; rebel", false}};

void print(vector<int>& forgotten){
    srand(time(NULL));
    int random_kanji;
    string str;

    while(kanji_data[random_kanji].was_shown){
        random_kanji = rand() % SIZE;
    }
    kanji_data[random_kanji].was_shown = true;

    cout << "\n█▄▀ ▄▀█ █▄░█ ░░█ █   █▀▀ █░░ ▄▀█ █▀ █░█   █▀▀ ▄▀█ █▀█ █▀▄ █▀\n" << 
              "█░█ █▀█ █░▀█ █▄█ █   █▀░ █▄▄ █▀█ ▄█ █▀█   █▄▄ █▀█ █▀▄ █▄▀ ▄█\n\n" << std::endl;

    cout << num << ". " <<  kanji_data[random_kanji].kanji;
    getline(cin, str);

    cout <<  '\n' << "----------" << '\n' << "Readings: " << kanji_data[random_kanji].readings << "\n" << "Meanings: " << kanji_data[random_kanji].meanings << '\n';

    getline(cin, str); 
    if(!str.empty()){
        forgotten.push_back(num - 1);
    }

    system("clear");
    if(num != SIZE && num != num_of_forgotten){
        num++;
        print(forgotten); 
    } else if(!forgotten.empty()) {
        cout << "Wait... you forgot some? Lets try again then";
        for(int i = 0; i < forgotten.size(); i++){
            kanji_data[forgotten[i]].was_shown = false;
        }
        num = 1;
        num_of_forgotten = forgotten.size();
        forgotten.clear();
        print(forgotten); 
    } else {
        cout << "You did everything, congratulations:D" << "\n";
    } 

    return;
}

int main(){
    system("clear");
    vector<int> forgotten;

    print(forgotten);

    return 0;
}