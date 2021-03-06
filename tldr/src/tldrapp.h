/* Copyright (c) 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef RSSAPP_H_
#define RSSAPP_H_

#include <QVariant>
#include <bb/cascades/Application>

namespace bb
{
    namespace cascades
    {
        class LocaleHandler;
    }
}

class QTranslator;

/**
 * Main class of the app, has a few utility functions for parsing RSSfeeds for
 * images and stripping out HTML.
 *
 * You will learn how to:
 * - Download images asynchronously
 * - Parse RSS
 */
class TLDRApp : public QObject
{
    Q_OBJECT

public:
    TLDRApp(bb::cascades::Application *app);
    virtual ~TLDRApp();

    /*
     * Utility function to strip html-formatting.
     *
     * @param htmlString The string that is going to be stripped.
     */
    Q_INVOKABLE QString plainText(const QString htmlString);

    /*
     * The RSS feed format has grown over the years, so we need to parse
     * the data to find the images
     *
     * @param item Data item containing an RSS entry that is parsed for a suitable image
     * @return A string with the image path return "" if no image was found
     */
    Q_INVOKABLE QString findImage(const QVariant item);

private:
    /**
     * System Language function, which will be attached to the signal emitted when
     * the system language change (for example if it is changed in the settings menu);
     */
    Q_SLOT void onSystemLanguageChanged();

    // Qt translator object used for loading translations.
    QTranslator* mTranslator;

    // The Locale handler used to query and listens for changes to system locales.
    bb::cascades::LocaleHandler* mLocaleHandler;
};

#endif /* RSSAPP_H_ */
