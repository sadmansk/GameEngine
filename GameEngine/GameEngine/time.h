#include <ctime>
#include <chrono>

static class Time
{
public:
	inline Time() : beg_(clock_::now()) {}
	void reset() { beg_ = clock_::now(); }

	double elapsed() const {
		return std::chrono::duration_cast<second_>
			(clock_::now() - beg_).count();
	}


	inline static void setDelta(double newDelta) { delta = newDelta; };
	inline static double getDelta() { return delta; }

	virtual ~Time();

private:
	typedef std::chrono::high_resolution_clock clock_;
	typedef std::chrono::duration<double, std::ratio<1> > second_;
	std::chrono::time_point<clock_> beg_;

	static double delta;
};