#include <iostream>
using namespace std;

struct Statinfo
{
    /* data */
    int hp;
    int attack;
    int defence;
};

// 주소 전달 방식
void CreateMonster(Statinfo *info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;
}

// 값 전달 방식
void CreateMonster(Statinfo info)
{
    info.hp = 100;
    info.attack = 8;
    info.defence = 5;
}

// 값을 수정하지 않는다면, 양쪽 다 문제 없음.

// 1. 값 전달 방식.

void PrintInfoByCopy(Statinfo info)
{
    cout << " ====== " << endl;
    cout << "HP :" << info.hp << endl;
}

// 2. 주소 전달 방식.
void PrintInfoByPointer(Statinfo *info)
{
    cout << " ====== " << endl;
    cout << "HP :" << info->hp << endl;

    // 2.1 포인터 const
    // 별 뒤에 붙는 경우
    // Statinfo* const info >> 주소값을 고치지 못하도록 함

    // 별 앞에 붙는 경우
    // const Statinfo* info >> 주소값에 해당하는 데이터를 고치지 못함.
}

// 구조체 자체가 엄청나게 커진다면 값 전달 방식에 성능문제가 생길 것.

// 3. 참조 전달
void PrintInfoByReference(const Statinfo &info)
{
    cout << " ====== " << endl;
    cout << "HP :" << info.hp << endl;

    // info.hp = 1000; // 오류
}

int main()
{
    // 참조의 이해
    int number = 1;
    int *pointer = &number;
    *pointer = 2;

    // 실제 작동 방식은 pointer랑 동일. 하지만 사용하는 방식은 값 전달과 동일.
    // C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
    int &reference = number;
    reference = 3; // number에 3을 바꾼다.

    // 귀찮게 왜씀?  >> 참조 전달 때문에.. >> 주소 전달 방법보면 화살표 좀 맘에 안듬.

    // 주소 전달 / 값 전달 비교
    Statinfo info;
    CreateMonster(&info);

    PrintInfoByCopy(info);

    // 참조 vs 포인터
    // 성능 : 똑같음
    // 편의성 : 참조 승.

    // 1) 편의성이 좋은게 꼭 좋은 것만은 아님.
    // 포인터를 주소를 넘기니 확실히 넘긴다는 힌트를 줄 수 있는데 .
    // 참조를 그렇지 않아 모르고 넘길 수 있다.
    PrintInfoByPointer(&info);
    PrintInfoByReference(info);

    // 마음대로 못고치도록 const사용해 개선할 수 있다. 그래서 reference랑 const가 세트로 등장하는 경우가 많다.
    // 포인터에서도 const를 사용가능 한데 ,
    // * 기준으로 앞 뒤로 붙는 경우 차이가 있다.

    // 2) 초기화 여부
    // 참조 타입은 바구니의 2번째 별칭 >> 참조하는 대상이 없으면 안된다.
    Statinfo *pointer1;
    pointer1 = &info;
    PrintInfoByPointer(pointer1);

    Statinfo &reference1; // 오류 초기화 필요
    // Statinfo& reference1 = info ;
    reference1 = info;
    PrintInfoByReference(reference1);

    return 0;
}
