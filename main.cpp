#include <Novice.h>

const char kWindowTitle[] = "宗てぃんぐ";


/*-----------------
    構造体を作る
-----------------*/

// 位置
struct Pos2
{
	float x;
	float y;
};

// ベクトル
struct Vec2
{
	float x;
	float y;
};

// 移動速度
struct Vel2
{
	float x;
	float y;
};

// 復活
struct Respawn
{
	// 復活しているかどうか（復活フラグ）
	int isRespawn;

	// 復活処理
	int timer;
};

// プレイヤー
struct Player
{
	// 復活
	struct Respawn respawn;

	// 位置
	struct Pos2 pos;

	// ベクトル
	struct Vec2 vec;

	// 移動速度
	struct Vel2 vel;

	// 図形の半径
	float radius;
};


/*---------------
    定数を作る
---------------*/

// 画面の横幅
const int kGameScreenWidth = 600;

// 画面の縦幅
const int kGameScreenHeight = 700;


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kGameScreenWidth + 300, kGameScreenHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	/*-----------------------------
	    変数を作り、初期値を入れる
	-----------------------------*/

	/*   プレイヤー   */

	// 構造体
	struct Player player;

	// 復活
	player.respawn.isRespawn = true;
	player.respawn.timer = 120;

	// 位置
	player.pos = { 0.0f , 0.0f };

	// ベクトル
	player.vec = { 0.0f , 0.0f };

	// 移動速度
	player.vel = { 0.0f , 0.0f };

	// 図形の半径
	player.radius = 0.0f;


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
