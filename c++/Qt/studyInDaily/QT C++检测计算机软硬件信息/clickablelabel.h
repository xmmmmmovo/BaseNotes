#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget *parent = 0);
    inline void setUrl(const QString& url);
    inline const QString& url();
    inline void setTitle(const QString& url);
    inline const QString& title();
signals:
    void clicked();

protected:
    virtual void mouseReleaseEvent(QMouseEvent*);

private:
    QString m_strUrl;
    QString m_strTitle;
};

inline void ClickableLabel::setUrl(const QString& url)
{
    m_strUrl = url;
}

inline const QString& ClickableLabel::url()
{
    return m_strUrl;
}

inline void ClickableLabel::setTitle(const QString& title)
{
    m_strTitle = title;
}

inline const QString& ClickableLabel::title()
{
    return m_strTitle;
}

#endif // CLICKABLELABEL_H
