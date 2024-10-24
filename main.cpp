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

	/*   ゲーム   */

	// ゲームが動いているかどうか（ゲームフラグ）
	int isGameOperation = false;

	// ゲームフレーム
	int gameFrame = 0;

	// ステージフレーム
	int stageFrame = 0;


	/*   画面   */

	// 画面の種類
	enum SCREEN_TYPE
	{
		SCREEN_TYPE_ORPNING,
		SCREEN_TYPE_START,
		SCREEN_TYPE_GAME,
		SCREEN_TYPE_END
	};

	// 現在の画面
	int screenNo = SCREEN_TYPE_START;

	// スタート画面の種類
	enum START_TYPE
	{
		START_TYPE_TITLE,
		START_TYPE_MAIN
	};

	// 現在のスタート画面
	int startNo = START_TYPE_TITLE;

	// メニューの種類
	enum MENU_TYPE
	{
		MENU_TYPE_TITLE,
		MENU_TYPE_GAME_START
	};

	// 現在のメニュー
	int menuNo = MENU_TYPE_TITLE;

	// ステージの種類
	enum STAGE_TYPE
	{
		STAGE_TYPE_TUTORIAL,
		STAGE_TYPE_1,
	};

	// 現在のステージ
	int stageNo = -1;


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

		/*--------------
		    画面操作
		--------------*/

		// ゲームが動いている（ゲームフラグがtrueである）ときに、ゲームフラグを進める
		if (isGameOperation)
		{
			gameFrame++;
		}

		// 画面切り替え
		switch (screenNo)
		{
		case SCREEN_TYPE_ORPNING:

			///
			/// ↓ オープニング画面ここから
			/// 

			///
			/// ↑ オープニング画面ここまで
			/// 

			break;

		case SCREEN_TYPE_START:

			///
			/// ↓ スタート画面ここから
			/// 

			// スタート画面切り替え
			switch (startNo)
			{
			case START_TYPE_TITLE:

				/*   タイトル画面   */

				if (menuNo == MENU_TYPE_TITLE)
				{
					// スペースキーで、チュートリアルに進む
					if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
					{
						if (isGameOperation == false)
						{
							// ゲームが動く（ゲームフラグがtrueになる）
							isGameOperation = true;
						}
					}

					// 50フレームで状態遷移する
					if (isGameOperation)
					{
						if (gameFrame >= 50)
						{
							// ゲーム画面に移る
							screenNo = SCREEN_TYPE_GAME;

							// チュートリアルステージ
							stageNo = STAGE_TYPE_TUTORIAL;


							// メイン画面に移る
							startNo = START_TYPE_MAIN;

							// ゲームスタートを選ぶ
							menuNo = MENU_TYPE_GAME_START;


							// ゲームが止まる（ゲームフラグがfalseになる）
							isGameOperation = false;

							// ゲームフレームが初期化される
							gameFrame = 0;
						}
					}
				}

				break;

			case START_TYPE_MAIN:

				/*   メイン画面   */

				break;
			}

			///
			/// ↑ スタート画面ここまで
			/// 

			break;

		case SCREEN_TYPE_GAME:

			///
			/// ↓ ゲーム画面ここから
			/// 

			/*-----------------
			    ステージ設定
			-----------------*/

			switch (stageNo)
			{
			case STAGE_TYPE_TUTORIAL:

				/*   チュートリアル   */

				break;

			case STAGE_TYPE_1:

				/*   ステージ1   */

				break;
			}

			stageFrame++;

			///
			/// ↑ ゲーム画面ここまで
			/// 

			break;

		case SCREEN_TYPE_END:

			///
			/// ↓ ゲーム終了画面ここから
			/// 

			///
			/// ↑ ゲーム終了画面ここまで
			/// 

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 画面切り替え
		switch (screenNo)
		{
		case SCREEN_TYPE_ORPNING:

			///
			/// ↓ オープニング画面ここから
			/// 

			///
			/// ↑ オープニング画面ここまで
			/// 

			break;

		case SCREEN_TYPE_START:

			///
			/// ↓ スタート画面ここから
			/// 

			///
			/// ↑ スタート画面ここまで
			/// 

			break;

		case SCREEN_TYPE_GAME:

			///
			/// ↓ ゲーム画面ここから
			/// 

			///
			/// ↑ ゲーム画面ここまで
			/// 

			break;

		case SCREEN_TYPE_END:

			///
			/// ↓ ゲーム終了画面ここから
			/// 

			///
			/// ↑ ゲーム終了画面ここまで
			/// 

			break;
		}

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
