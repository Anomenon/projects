#include <iostream>
#include <vector>
using namespace std;

string kanji[394] = {"一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "百", "千", "万", "円", "日", "週", "月", "年", "時", "間", "分", "午", "前", "後", "今", "先", 
    "来", "半", "毎", "何", "人", "男", "女", "子", "母", "父", "友", "火", "水", "木", "土", "金", "本", "川", "花", "気", "生", "魚", "天", "空", "山", "雨", "電", "車", "語", 
    "耳", "手", "足", "目", "口", "名", "店", "駅", "道", "社", "国", "外", "学", "校", "上", "下", "中", "北", "東", "南", "西", "右", "左", "字", "見", "聞", "書", "読", "話", 
    "行", "出", "入", "休", "食", "飲", "言", "立", "会", "多", "少", "古", "新", "大", "小", "安", "高", "長", "白", "私", "竜", "秒", "文", "化", "森", "守", "田", "世", "死", 
    "待", "者", "漢", "曜", "英", "力", "音", "犬", "方", "地", "京", "用", "家", "画", "海", "黒", "春", "秋", "夏", "冬", "昼", "茶", "走", "色", "弟", "兄", "妹", "姉", "愛", 
    "氷", "了", "体", "丈", "夫", "毛", "持", "当", "穴", "良", "不", "児", "止", "心", "々", "仁", "回", "運", "同", "可", "彼", "閉", "許", "注", "全", "合", "明", "専", "伝", 
    "次", "祖", "記", "事", "青", "緑", "黄", "赤", "紫", "之", "工", "貴", "保", "護", "正", "元", "次", "番", "常", "宮", "村", "禁", "石", "互", "俺", "連", "泣", "猫", "鳥", 
    "自", "晩", "内", "覚", "太", "固", "久", "波", "娘", "息", "夜", "狭", "苦", "早", "遅", "法", "住", "主", "凄", "妻", "稲", "任", "楽", "難", "差", "玉", "卵", "抜", "腰", 
    "影", "島", "根", "屋", "族", "草", "竹", "性", "格", "的", "具", "資", "際", "実", "施", "布", "共", "有", "貼", "得", "意", "振", "込", "返", "使", "館", "図", "構", "管", 
    "総", "選", "予", "防", "定", "舌", "平", "辞", "典", "係", "数", "最", "初", "触", "媒", "受", "取", "変", "開", "平", "曲", "線", "王", "員", "弁", "士", "顔", "面", "池", 
    "択", "町", "雪", "貝", "糸", "虫", "林", "場", "米", "通", "首", "作", "強", "市", "公", "野", "思", "点", "活", "原", "交", "近", "考", "売", "組", "知", "引", "計", "直", 
    "台", "広", "夕", "教", "切", "算", "親", "形", "頭", "門", "答", "帰", "谷", "歌", "光", "科", "細", "丸", "室", "歩", "風", "紙", "戸", "園", "料", "無", "第", "界", "歳", 
    "冒", "転", "際", "達", "魔", "異", "映", "勉", "起", "寝", "然", "飯", "末", "単", "身", "問", "角", "沼", "美", "短", "軽", "羽", "船", "笑", "岩", "雲", "鳴", "弓", "港", 
    "路", "悪", "他", "橋", "岸", "客", "登", "速", "央", "買", "始", "好", "声", "酉", "霧", "理", "沼", "朝", "君", "階"};

int main(){
    vector<int> Nums;

    while(Nums.size() != 394){
        bool dupa = false;
        int randomNumber = (rand() % 394);

        for(int i = 0; i < Nums.size(); i++){
            if(randomNumber == Nums[i]){
                dupa = true;
            }
        }

        string str;
        if(dupa != true){
            Nums.push_back(randomNumber);
            
            cout << "██╗░░██╗░█████╗░███╗░░██╗░░░░░██╗██╗\n" << 
                    "██║░██╔╝██╔══██╗████╗░██║░░░░░██║██║\n" << 
                    "█████═╝░███████║██╔██╗██║░░░░░██║██║\n" << 
                    "██╔═██╗░██╔══██║██║╚████║██╗░░██║██║\n" << 
                    "██║░╚██╗██║░░██║██║░╚███║╚█████╔╝██║\n" << 
                    "╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝░╚════╝░╚═╝\n" << std::endl;

            cout << kanji[randomNumber] << '\n';
            while(getline(cin, str)){
                if(str.empty()){
                    system("clear");
                    break;
                }

            }   
        } 
        
    }
    cout << "Nice you've done everything:DD" << '\n';
    
    return 0;
};