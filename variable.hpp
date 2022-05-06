#pragma once

enum class varType {
	COCHEE,
	MENTEUR,
};

class Variable final {
	public:
	constexpr Variable(int i = -1) noexcept
		: type(varType::COCHEE), index(i), neg(false) { }

	constexpr Variable(const Variable& v1) = default;
	constexpr bool operator==(const Variable& v1) const {
		return (type == v1.type) && (index == v1.index) && (neg == v1.neg);
	}

	private:
	varType type;
	int index;
	bool neg;

	public:
	constexpr varType GetType() const { return type; }
	constexpr bool GetNeg() const { return neg; }
	constexpr int GetIndex() const { return index; }

	constexpr void SetType(varType _type) { type = _type; }
	constexpr void SetNeg(bool _neg) { neg = _neg; }
	constexpr void SetIndex(int _index) { index = _index; }
};