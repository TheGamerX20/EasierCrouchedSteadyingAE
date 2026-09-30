#pragma once

namespace EasierCrouchedSteadying
{
	static REX::TOML::F32 fCrouchedSteadyMult{ "Configs"sv, "fCrouchedSteadyMult"sv, 0.5f };

	namespace easierCrouchedSteadyingDetail
	{
		struct CalcScopeSteadyActionPointDrain // CombatFormulas::CalcScopeSteadyActionPointDrain()
		{
			static void thunk(RE::Actor* a_actor, float a_deltaSec, void* a_a3, void* a_a4)
			{
				if (a_actor->IsSneaking())
					return func(a_actor, a_deltaSec * fCrouchedSteadyMult.GetValue(), a_a3, a_a4);

				return func(a_actor, a_deltaSec, a_a3, a_a4);
			}

			static inline REL::Relocation<decltype(thunk)> func;
		};

	}

	inline bool Install()
	{
		easierCrouchedSteadyingDetail::CalcScopeSteadyActionPointDrain::func = REL::GetTrampoline().write_call<5>(REL::Relocation<uintptr_t>(REL::ID{ 355149, 2224472 }, REL::Offset{ 0x3D }).address(), easierCrouchedSteadyingDetail::CalcScopeSteadyActionPointDrain::thunk);
		return easierCrouchedSteadyingDetail::CalcScopeSteadyActionPointDrain::func != 0;
	}
}
