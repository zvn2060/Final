#ifndef FLAG_HPP
#define FLAG_HPP

class Flag {
public:
  Flag() {
	this->flags = 0;
  }

  bool isFlagSet(int target) {
	return this->flags & target ? true : false;
  }

  // return true if the target flag has change
  bool setFlag(int target) {
	bool pre = this->isFlagSet(target);
	this->flags |= target;
	return !pre;
  }
  bool clearFlag(int target) {
	bool pre = this->isFlagSet(target);
	this->flags &= ~target;
	return pre;
  }
private:
  // at most 32 types of flag
  int flags;
};

#endif