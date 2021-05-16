/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Chrono.inl
*/

inline plz::Chrono::Chrono() :
    m_isRuning(false)
{}

inline plz::Chrono::Chrono(ctorState state) :
    m_isRuning(false)
{
    if (state == Lauch) {
        m_isRuning = true;
        start();
    }
}

inline void plz::Chrono::start()
{
    m_start = std::chrono::steady_clock::now();
    m_end = m_start;
    m_tour = m_start;
    m_isRuning = true;
}

inline void plz::Chrono::stop()
{
    if (m_isRuning == true)
        m_end = std::chrono::steady_clock::now();
    m_isRuning = false;
}

inline void plz::Chrono::tour()
{
    m_tour = m_end;
}

inline double plz::Chrono::getElapsedTime() const
{
    if (m_isRuning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

inline double plz::Chrono::getTotalTime() const
{
    if (m_isRuning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
    return (step / 1000);
}