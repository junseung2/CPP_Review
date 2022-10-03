// 객체 지향 프로그래밍의 key point
// class는 일종의 설계도.
// 1. Object
// 2. Constructor   생성 소속자는 멤버함수의 특별한 경우 (시작과 끝.)
// 3. Destructor

// 생성자를 명시적으로 만들지 않으면, 기본 생성자 자동으로 컴파일러에 의해 만들어지며,
// 명시적으로 아무 생성자 하나 만드는 순간, 기본 생성사자는 자동으로 안 만들어짐. 오류의 주 원인. 생각해서 만들어 주자.

#include <iostream>
using namespace std;

class Knight
{
public:
    // Member variable
    int _hp;
    int _attack;
    int _posX;
    int _posY;

public:
    // 기본 생성자.
    Knight()
    {
        cout << "Knight() Constructor" << endl;
        _hp = 100;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }

    // 기타 생성자 (매개변수 있다.) , 타입변환 생성자라고도 함.
    explicit Knight(int hp)
    {
        cout << "Knight (int hp) Constructor" << endl;
        _hp = hp;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }

    // 복사 생성자 자기 자신의 참조값을 인자로 받는다.
    Knight(const Knight &knight)
    {
        cout << "Knight Copy Constructor" << endl;
        _hp = knight._hp;
        _attack = knight._attack;
        _posX = knight._posX;
        _posY = knight._posY;
    }

    // 소멸자는 한번만.
    ~Knight() { cout << "Knight() Destructor" << endl; }

    // Member function
    void Move(int x, int y);
    void Attack();
    void Die()
    {
        // this->_hp = 0; 밑과 동일한 코드. this가 생략되어 있었음.
        _hp = 0;
        cout << "Dead" << endl;
    }
};

int main()
{
    Knight k1;

    k1.Move(2, 3);
    k1.Attack();
    k1.Die();

    Knight k2(50);

    Knight k3(k1);  // k1과 동일한 knight k3 생성. 똑같은 데이터를 지닌 객체가 생성된다.
    Knight k4 = k1; // 이 방식도 복사 생성자 이용한 방식

    Knight k5; // 이 방식은 복사 생성자는 아님. 기본 생성자가 생성된 후 k1 복사한다.
    k5 = k1;

    // 암시적 형변환 -> 컴파일러가 알아서 바꿔치기.
    int num = 1;
    float f = num;

    // 명시적 형변환
    float f1 = (float)num;

    // 객체와 특정 형 변환 가능? 타입 변환 생성자 호출됨.
    Knight k5;
    // k5 = 1; // 이런경우가 암시적 형 변환이 일어남. 컴파일러가 계속 개입함. 이런게 싫으면 explicit 키워드 추가. 이러면 에러남.

    return 0;
}

void Knight::Move(int x, int y)
{
    _posX = x;
    _posY = y;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack " << _attack << endl;
}
