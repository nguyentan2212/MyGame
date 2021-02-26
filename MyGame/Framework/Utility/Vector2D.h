#pragma once
class Vector2D
{
public:
	Vector2D() { this->x = 0; this->y = 0; }
	Vector2D(double x, double y) { this->x = x; this->y = y; }
	void SetVector(double x, double y) { this->x = x; this->y = y; }
	void SetVector(Vector2D vec) { this->x = vec.x; this->y = vec.y; }
	double GetX() { return x; }
	double GetY() { return y; }
	void SetX(double x) { this->x = x; }
	void SetY(double y) { this->y = y; }
	Vector2D operator+(const Vector2D& vec);
	Vector2D operator-(const Vector2D& vec);
	Vector2D operator*(const double f);
	Vector2D operator/(const double f);
	bool operator==(const Vector2D& vec);
	bool operator!=(const Vector2D& vec);

	static Vector2D Up() { return Vector2D(0.0f, -1.0f); }
	static Vector2D Down() { return Vector2D(0.0f, 1.0f); }
	static Vector2D Left() { return Vector2D(-1.0f, 0.0f); }
	static Vector2D Right() { return Vector2D(1.0f, 0.0f); }
	static Vector2D Zero() { return Vector2D(); }

private:
	double x;
	double y;
};

typedef Vector2D* LPVECTOR2D;