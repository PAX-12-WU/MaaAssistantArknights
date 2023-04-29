#pragma once

#include "Vision/OnnxHelper.h"

namespace asst
{
    // 战斗中干员（血条）检测，yolov8 模型
    class BattleOperatorsImageAnalyzer final : public OnnxHelper
    {
    public:
        enum class Cls
        {
            Operator = 0,
        };
        struct Box
        {
            Cls cls = Cls::Operator;
            Rect rect;
            float score = .0f;
        };

    public:
        using OnnxHelper::OnnxHelper;
        virtual ~BattleOperatorsImageAnalyzer() override = default;

        bool analyze();

        const std::vector<Box>& get_results() const { return m_results; }
#ifdef ASST_DEBUG
        const std::vector<Rect>& get_draw_rect() const { return m_draw_rect; }
#endif

    private:
        std::vector<Box> m_results;

#ifdef ASST_DEBUG
        std::vector<Rect> m_draw_rect;
#endif
    };
}
