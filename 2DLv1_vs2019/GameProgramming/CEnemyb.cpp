#include"CEnemyb.h"
#include"CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

//CBullet CEnemyb::EBullet[20];

CEnemyb::CEnemyb()
	: mFx(1.0f), mFy(0.0f), mFireCount(80)
{
	//37
//	mEnabled = true;
	mTag = EENEMYB;
	w = 30;
	h = 30;
}

void CEnemyb::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//37s
		//弾を発射する
		for (int i = 2; i < 3; i++) {
			CBullet* EBullet = new CBullet();
			//座標設定
			EBullet->x = x;
			EBullet->y = y;
			//移動量設定
			EBullet->mFx = (i - 2) % 2 * 2;
			EBullet->mFy = (i - 1) % 2 * 2 * -1;
			//有効にする
			EBullet->mEnabled = true;
			EBullet->mTag = EENEMYBULLET;
		}
		mFireCount = 120;
		//37e
/* 37
//敵弾数分繰り返し
for (int i = 0; i < 20; i++) {
	//無効な弾なら発射する
	if (!EBullet[i].mEnabled) {
		//座標設定
		EBullet[i].x = x;
		EBullet[i].y = y;
		//移動量設定
		EBullet[i].mFx = 2;
		EBullet[i].mFy = 0;
		//有効にする
		EBullet[i].mEnabled = true;
		EBullet[i].mTag = EENEMYBULLET;
		//発射間隔を60フレームにする
		break;
	}
	mFireCount = 60;
}
//敵弾数分繰り返し
for (int i = 0; i < 20; i++) {
	//無効な弾なら発射する
	if (!EBullet[i].mEnabled) {
		//座標設定
		EBullet[i].x = x;
		EBullet[i].y = y;
		//移動量設定
		EBullet[i].mFx = -2;
		EBullet[i].mFy = 0;
		//有効にする
		EBullet[i].mEnabled = true;
		EBullet[i].mTag = EENEMYBULLET;
		//発射間隔を60フレームにする
		break;
	}
	mFireCount = 60;
}
//敵弾数分繰り返し
for (int i = 0; i < 20; i++) {
	//無効な弾なら発射する
	if (!EBullet[i].mEnabled) {
		//座標設定
		EBullet[i].x = x;
		EBullet[i].y = y;
		//移動量設定
		EBullet[i].mFx = 0;
		EBullet[i].mFy = 2;
		//有効にする
		EBullet[i].mEnabled = true;
		EBullet[i].mTag = EENEMYBULLET;
		//発射間隔を60フレームにする
		break;
	}
	mFireCount = 60;
}
//敵弾数分繰り返し
for (int i = 0; i < 20; i++) {
	//無効な弾なら発射する
	if (!EBullet[i].mEnabled) {
		//座標設定
		EBullet[i].x = x;
		EBullet[i].y = y;
		//移動量設定
		EBullet[i].mFx = 0;
		EBullet[i].mFy = -2;
		//有効にする
		EBullet[i].mEnabled = true;
		EBullet[i].mTag = EENEMYBULLET;
		//発射間隔を60フレームにする
		break;
	}
	mFireCount = 60;
}
*/
	}
	x += mFx;
	y += mFy;
}

/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemyb::Collision(const CRectangle& r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return false;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			//衝突していれば反転
			/*mFx *= -1;
			mFy *= -1;*/
			break;
		case EPLAYERBULLET:
			//プレイヤーの弾に当たると、無効にする
			mEnabled = false;
			break;
		case EPLAYER:
			mEnabled = false;
			break;
		}
		return true;
	}
	return false;
}

void CEnemyb::Render() {
	if (mEnabled) {
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16);
	}
}

//36
void CEnemyb::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}