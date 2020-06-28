//Find
	rkPlayer.SetStatus(PointChange.Type, PointChange.value);
	
///Change
#if defined(REFRESH_MONEY_SLEEP)
		if (PointChange.Type == POINT_GOLD) {
			auto DoChanges = [=](long val, bool IsGrowing) {
				long long wait = 0;
				if (abs(PointChange.value - val) < 10000) 
					wait = 1;
				for (; val <= PointChange.value && IsGrowing; val++) {
					CPythonPlayer::Instance().SetStatus(PointChange.Type, val);
					std::this_thread::sleep_for(std::chrono::nanoseconds(wait));
				}
				for (; val >= PointChange.value && !IsGrowing; val--) {
					CPythonPlayer::Instance().SetStatus(PointChange.Type, val);
					std::this_thread::sleep_for(std::chrono::nanoseconds(wait));
				}
			};
			std::thread mythread(DoChanges, static_cast<long>(CPythonPlayer::Instance().GetStatus(PointChange.Type)), CPythonPlayer::Instance().GetStatus(PointChange.Type) < PointChange.value);
			if (mythread.joinable())
				mythread.detach(); // do not use join()
			else
				rkPlayer.SetStatus(PointChange.Type, PointChange.value);
		}
		else
#endif
		rkPlayer.SetStatus(PointChange.Type, PointChange.value);
