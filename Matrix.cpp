#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include "Structure.h"
#include "Matrix.h"

/// <summary>
/// 拡大縮小行列を作る
/// </summary>
/// <param name="scale">大きさ</param>
/// <returns>拡大縮小行列の構造体を返却する</returns>
struct Matrix3x3 MakeScaleMatrix(Vec2 scale)
{
	// 拡大縮小行列
	struct Matrix3x3 scaleMatrix;

	scaleMatrix.m[0][0] = scale.x;
	scaleMatrix.m[0][1] = 0.0f;
	scaleMatrix.m[0][2] = 0.0f;

	scaleMatrix.m[1][0] = 0.0f;
	scaleMatrix.m[1][1] = scale.y;
	scaleMatrix.m[1][2] = 0.0f;

	scaleMatrix.m[2][0] = 0.0f;
	scaleMatrix.m[2][1] = 0.0f;
	scaleMatrix.m[2][2] = 1.0f;

	return scaleMatrix;
}

/// <summary>
/// 回転行列を作る
/// </summary>
/// <param name="theta">角度</param>
/// <returns>回転行列の構造体を返却する</returns>
struct Matrix3x3 MakeRotateMatrix(float theta)
{
	// 回転行列
	struct Matrix3x3 rotateMatrix;

	rotateMatrix.m[0][0] = cosf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[0][1] = sinf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[0][2] = 0.0f;

	rotateMatrix.m[1][0] = -sinf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[1][1] = cosf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[1][2] = 0.0f;

	rotateMatrix.m[2][0] = 0.0f;
	rotateMatrix.m[2][1] = 0.0f;
	rotateMatrix.m[2][2] = 1.0f;

	return rotateMatrix;
}

/// <summary>
/// 平行移動行列を作る
/// </summary>
/// <param name="translate">平行移動</param>
/// <returns>平行移動行列の構造体を返却する</returns>
struct Matrix3x3 MakeTranslateMatrix(Vec2 translate)
{
	// 平行移動行列
	struct Matrix3x3 translateMatrix;

	translateMatrix.m[0][0] = 1.0f;
	translateMatrix.m[0][1] = 0.0f;
	translateMatrix.m[0][2] = 0.0f;

	translateMatrix.m[1][0] = 0.0f;
	translateMatrix.m[1][1] = 1.0f;
	translateMatrix.m[1][2] = 0.0f;

	translateMatrix.m[2][0] = translate.x;
	translateMatrix.m[2][1] = translate.y;
	translateMatrix.m[2][2] = 1.0f;

	return translateMatrix;
}

/// <summary>
/// 行列の積を求める
/// </summary>
/// <param name="matrix1">行列1</param>
/// <param name="matrix2">行列2</param>
/// <returns>行列の積を求めた構造体を返却する</returns>
struct Matrix3x3 Multiply(struct Matrix3x3 matrix1, struct Matrix3x3 matrix2)
{
	// 行列の積
	struct Matrix3x3 multiplyMatrix;

	multiplyMatrix.m[0][0] = matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0] + matrix1.m[0][2] * matrix2.m[2][0];
	multiplyMatrix.m[0][1] = matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1] + matrix1.m[0][2] * matrix2.m[2][1];
	multiplyMatrix.m[0][2] = matrix1.m[0][0] * matrix2.m[0][2] + matrix1.m[0][1] * matrix2.m[1][2] + matrix1.m[0][2] * matrix2.m[2][2];

	multiplyMatrix.m[1][0] = matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0] + matrix1.m[1][2] * matrix2.m[2][0];
	multiplyMatrix.m[1][1] = matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1] + matrix1.m[1][2] * matrix2.m[2][1];
	multiplyMatrix.m[1][2] = matrix1.m[1][0] * matrix2.m[0][2] + matrix1.m[1][1] * matrix2.m[1][2] + matrix1.m[1][2] * matrix2.m[2][2];

	multiplyMatrix.m[2][0] = matrix1.m[2][0] * matrix2.m[0][0] + matrix1.m[2][1] * matrix2.m[1][0] + matrix1.m[2][2] * matrix2.m[2][0];
	multiplyMatrix.m[2][1] = matrix1.m[2][0] * matrix2.m[0][1] + matrix1.m[2][1] * matrix2.m[1][1] + matrix1.m[2][2] * matrix2.m[2][1];
	multiplyMatrix.m[2][2] = matrix1.m[2][0] * matrix2.m[0][2] + matrix1.m[2][1] * matrix2.m[1][2] + matrix1.m[2][2] * matrix2.m[2][2];

	return multiplyMatrix;
}

/// <summary>
/// ベクトルと行列の積を求める
/// </summary>
/// <param name="vector">ベクトル</param>
/// <param name="matrix">行列</param>
/// <returns>ベクトルと行列の積を求めた構造体を返却する</returns>
struct Vec2 Transform(struct Vec2 vector, struct Matrix3x3 matrix)
{
	// ベクトルと行列の積
	struct Vec2 transform;

	transform.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	transform.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];

	assert(w != 0.0f);

	transform.x /= w;
	transform.y /= w;

	return transform;
}

/// <summary>
/// アフィン行列を作る
/// </summary>
/// <param name="scale">大きさ</param>
/// <param name="theta">角度</param>
/// <param name="transform">平行移動</param>
/// <returns>アフィン行列の構造体を返却する</returns>
struct Matrix3x3 MakeAffineMatrix(struct Vec2 scale, float theta, struct Vec2 transform)
{
	// アフィン行列
	struct Matrix3x3 worldMatrix = Multiply(MakeScaleMatrix(scale), MakeRotateMatrix(theta));
	worldMatrix = Multiply(worldMatrix, MakeTranslateMatrix(transform));

	return worldMatrix;
}