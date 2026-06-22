from manim import *

class TamimIntro(Scene):
    def construct(self):
        # Background color
        self.camera.background_color = "#813434"

        # ── Letter-by-letter write-on ──────────────────────────────
        letters = VGroup(*[
            Text(ch, font="Helvetica Neue", weight=BOLD, font_size=120, color=WHITE)
            for ch in "TAMIM"
        ])
        letters.arrange(RIGHT, buff=0.15)
        letters.move_to(ORIGIN)

        for letter in letters:
            letter.save_state()
            letter.set_opacity(0)
            letter.shift(DOWN * 0.6)

        self.play(
            AnimationGroup(
                *[
                    Restore(letter, run_time=0.4)
                    for letter in letters
                ],
                lag_ratio=0.18
            )
        )
        self.wait(0.3)

        # ── Colour sweep: white → electric blue ───────────────────
        self.play(
            letters.animate.set_color("#4DAAFF"),
            run_time=0.8,
            rate_func=smooth
        )
        self.wait(0.2)

        # ── Underline draws itself ─────────────────────────────────
        underline = Line(
            letters.get_left() + DOWN * 0.72,
            letters.get_right() + DOWN * 0.72,
            color="#4DAAFF",
            stroke_width=4
        )
        self.play(Create(underline), run_time=0.6)
        self.wait(0.2)

        # ── Subtitle fades in ──────────────────────────────────────
        subtitle = Text(
            "RUET · CSE · Ethical Hacker",
            font="Helvetica Neue",
            font_size=28,
            color=GRAY
        )
        subtitle.next_to(underline, DOWN, buff=0.45)
        self.play(FadeIn(subtitle, shift=UP * 0.2), run_time=0.7)
        self.wait(0.5)

        # ── Pulse effect on the name ───────────────────────────────
        self.play(
            letters.animate.scale(1.08),
            run_time=0.35,
            rate_func=there_and_back
        )
        self.wait(0.4)

        # ── Everything slides up and fades out ────────────────────
        everything = VGroup(letters, underline, subtitle)
        self.play(
            everything.animate.shift(UP * 0.5).set_opacity(0),
            run_time=0.8,
            rate_func=smooth
        )
        self.wait(0.2)